## DFC 运行库

> <p align="right">author: 李克钹 <br> email: 565853000@qq.com</p>
 
----------------

##### DFC运行库包含三部分，c_printf（自己封装的格式化输出库），threadpool（使用pthread实现的线程池库），dfc库（数据流相关的实现），



* 线程池：

  1. 主要的几个结构体：

```
// 每一个具体的任务（就是一个待运行的函数，记录了函数指针和函数参数）
typedef struct {
    void (*function)(void *);
    void *argument;
    int item_index;
} threadpool_task_t;

// 线程池的结构体
struct threadpool_t {
  pthread_mutex_t lock;       // 线程池的全局锁
  pthread_cond_t notify;      // 信号量，做通信功能
  pthread_t *threads;         // pthread数组，线程池实际的线程数
  threadpool_task_t *queue;   // 任务队列，保存了所有的待运行任务（这里是当做循环队列来使用，使用head和tail来指示队列的头尾）
  int* thread_task;           // 线程正在执行A任务
  int thread_in_run_count;    //有多少个线程正在执行函数  其余线程空闲
  int thread_count;
  int queue_size;
  int head;
  int tail;
  int count;
  int shutdown;
  int started;
};

// 一个指明是线程池中哪个线程的结构体，通过index来表明是第几个线程
typedef struct pool_index_record {
  void* pool;  
  int index;
} record ;
```

线程池结构图示如下：
![threadpool_struct](./pic/dfc_runtime/threadpool_struct.png "线程池结构")


  2. 线程池几个函数中的主要部分摘取：

![threadpool_func](./pic/dfc_runtime/threadpool_func.png "线程池主要函数")

```
// 线程创建
threadpool_t *threadpool_create(int thread_count, int queue_size, int flags){
    threadpool_t *pool;
    
    /*  初始化参数，分配空间  */
    
    // 根据参数初始化线程数组
    for(i = 0; i < thread_count; i++) {
         record *pool_record;
         pool_record = (record*)malloc(sizeof(record));
         pool_record->pool = (void*)pool;
        pool_record->index = i;
        pool->thread_task[i] = -1;   
        // 对每一个线程启动调用一次threadpool_thread函数进入工作状态
        if(pthread_create(&(pool->threads[i]), NULL,
                          threadpool_thread, (void*)pool_record) != 0) {
            threadpool_destroy(pool, 0);
            return NULL;
        }
        pool->thread_count++;
        pool->started++;
    }
    
    // 错误处理
}

// 增加任务
int threadpool_add(threadpool_t *pool, void (*function)(void *),
                   void *argument, int flags)
{
        /* 变量合法性判断，获取锁*/
         
        /* 计算下一个可以存储 task 的位置*/
        next = pool->tail + 1;
        next = (next == pool->queue_size) ? 0 : next; // 循环队列
        
        // 将参数存入队列中，
        pool->queue[pool->tail].function = function;
        pool->queue[pool->tail].argument = argument;
        pool->queue[pool->tail].item_index = flags;
        /* 更新 tail 和 count */
        pool->tail = next;
        pool->count += 1;

        /* pthread_cond_broadcast */
        /*
         * 发出 signal,表示有 task 被添加进来了
         * 如果由因为任务队列空阻塞的线程，此时会有一个被唤醒
         * 如果没有则什么都不做
         */
        if(pthread_cond_signal(&(pool->notify)) != 0) {
            err = threadpool_lock_failure;
            break;
        }    
        
        // 解锁
}              

// 线程池销毁
int threadpool_destroy(threadpool_t *pool, int flags)
{
    // 加锁
    
    /* Wake up all worker threads */
    /* 唤醒所有因条件变量阻塞的线程，并释放互斥锁 */
    if((pthread_cond_broadcast(&(pool->notify)) != 0) ||
        (pthread_mutex_unlock(&(pool->lock)) != 0)) {
        err = threadpool_lock_failure;
        break;
    }

    /* Join all worker thread */
    /* 等待所有线程结束 */
    for(i = 0; i < pool->thread_count; i++) {
        if(pthread_join(pool->threads[i], NULL) != 0) {
            err = threadpool_thread_failure;
        }
    
    // 释放资源
}         

// 线程主函数，参数为一个线程，实际为 pool_index_record 指针  
static void *threadpool_thread(void* param){
    
    // 解析参数为pool_index_record
    
    // 一个死循环，不停从任务队列中取任务
    for(;;) {
        // 加锁
       pthread_mutex_lock(&(pool->lock));

        /* Wait on condition variable, check for spurious wakeups.
           When returning from pthread_cond_wait(), we own the lock. */
        /* 用 while 是为了在唤醒时重新检查条件 */
        while((pool->count == 0) && (!pool->shutdown)) {
            /* 任务队列为空，且线程池没有关闭时阻塞在这里 */
            pthread_cond_wait(&(pool->notify), &(pool->lock));
        }

        /* 关闭的处理 */
        if((pool->shutdown == immediate_shutdown) ||
           ((pool->shutdown == graceful_shutdown) &&
            (pool->count == 0))) {
            break;
        }

        /* Grab our task */
        /* 取得任务队列的第一个任务 */
        task.function = pool->queue[pool->head].function;
        task.argument = pool->queue[pool->head].argument;
        /* 更新 head 和 count */
        pool->thread_in_run_count += 1;
        pool->head += 1;
        pool->head = (pool->head == pool->queue_size) ? 0 : pool->head;
        pool->count -= 1;
        pool->thread_task[index] = pool->queue[pool->head].item_index;

        /* Unlock */
        /* 释放互斥锁 */
        pthread_mutex_unlock(&(pool->lock));

        /* Get to work */
        /* 开始运行任务 */
        (*(task.function))(task.argument);
        /* 这里一个任务运行结束 */
        pthread_mutex_lock(&(pool->lock));
        pool->thread_in_run_count -= 1;
        pool->thread_task[index] = -1;
        pthread_mutex_unlock(&(pool->lock));     
    }         
}
```

* DFC库：

>dfc的运行机制就是利用dfcc的编译，生成新的主函数，并在原来的主函数和DFC函数中插入DFC运行库的相关函数，之后调用dfc库中相关的函数完成运行，主要的改变主要如下图：

![dfc_func](./pic/dfc_runtime/dfc_func.png "DFC主要函数")

 1. 几个主要的结构体
``` 
// DF_TFL 全局表
struct DF_TargetFunList{
    int Num;             //输出目标的数据流节点数
    DF_FN **Target;      //输出目标的数据流函数指针线性表
    threadpool_t* pool;  // 线程池
    DF_SI* source_list;
    int source_list_len;
    DF_AD** output_list;
    int output_list_len;
    void** result;
    void (**Func_Target) (void *);
    int* item_index_order;
    int should_hash;
    int thread_num;
    int* thread_task;
};   //线性表结构

// active data，DF_AD
struct Active_Data{
    int Data_Count;                 //用于记录链上有多>少个数据对象可用    00 缓冲区数量   单位/个
    int Sum;                    //至今有过多少数据量           单位/个
    void *Data;
    int   Head;               //头尾 单位/个
    int   Tail;
    int   Order;
    // int * ?
    int   MaxSize;
    int   persize;//数据单位大小             单位字节       size+4
    int FanOut;                      //指向几个目标函数

    // 这里也应该用函数指针列表吧
    DF_FN **DF_Fun_Index;           //指向目标数据流函数的 数据块二级指针      指向指针的指针
    // 指向数据流函数的数据，目前来看 Active Data 应该是唯一的
    int*   DF_flag_Index;          //是第几位
    pthread_rwlock_t lock;
};//主动数据链路

// DF_TADL
struct DF_TargetADList{
  int TargetNum;           //输入/输出主动数据数目
  DF_AD * Target[];   // 输入/输出主动数据指针 线性表
};

// 每一个函数节点，DF_FN
struct DF_Fun_Node {
    //DF_FN     * next_fun;                     //构成>线性链表
    //DF_FN     * next_ready_on_CPU;                //>挂入某个CPU的就绪队列
    //DF_sched_data sched_data;                 //调度>数据
    //DF_DAG_node   DAG_node;                       //>数据流图节点
    int item_index;                                //数据流节点编号
    void        (*Func)(void);                      //>数据流函数
    unsigned        char * Name;                    //>函数名
        DF_Ready*       ready;                   // 记录参数的准备状态
    pthread_mutex_t ready_lock;                 //就绪队列锁---保证不同的FN输出为1个FN的输入就绪队列的访问
    int             FinishNum;                        //当前已经派发出去的任务数
    int             realFinishNum;                     //当前真正完成了几个工作，初始为0   用以从数据端获得正确数据
    int stop;  //停止运行标志
    pthread_rwlock_t finish_lock;               //fn 顺序锁    保证同一个fn的不同次执行的顺序   保证getdata
    pthread_rwlock_t realfinish_lock;           //保证updata
    DF_TADL*      DF_Fun_AD_InPut;                          //输入主动数据块
    // 每次运行时都要从这取数据吗？
    // 数据分配是怎样一个操作呢
    DF_TADL*      DF_Fun_AD_OutPut;                      //输出主动链块
    // 塞数据到里面
};

// DF_Ready 记录通过位运记录参数的准备状态，int32位，因此能保存32个参数的状态
struct DF_Ready_Flags {
  int Flags;
  struct DF_Ready_Flags *next;
};
```

主要结构体关系图：

![dfc_struct](./pic/dfc_runtime/dfc_struct.png "DFC主要结构体关系")


2. 主要函数：
>这里主要是一个C的标准库   stdarg.h 的使用，用来获取函数里的可变参数，看一下相应的API后，阅读代码就比较流畅 ：

```
void DF_ADInit(DF_AD* AD, int persize,int FanOut) {
    // 变量初始化
}

// FN初始化函数一，  连接输入和FN节点的关系（FN指向AD，AD指向FN）
void DF_FNInit1(DF_FN* FN,void*FunAddress ,char *Name, int InPutADNum,...){
   // 使用stdarg库，获取参数信息，写入FN中 
}

//FN初始化函数二，连接FN节点和输出AD关系
void DF_FNInit2(DF_FN *FN, int OutPutADNum, ...){
  // 使用stdarg库，获取参数信息，写入FN中
  va_list ap;
  va_start(ap,OutPutADNum);
  FN->DF_Fun_AD_OutPut = (DF_TADL*)malloc(sizeof(DF_TADL) + OutPutADNum * sizeof(DF_AD*));  //柔性数组使用的指针数组 可能有BUG
  FN->DF_Fun_AD_OutPut->TargetNum = OutPutADNum;
  for(int i = 0;i < OutPutADNum;i++){
    FN->DF_Fun_AD_OutPut->Target[i] = va_arg(ap,DF_AD*);
  }
  va_end(ap); 
}

// 初始化源输入函数
void DF_SourceInit(DF_TFL *table, int sourcenum, ...) {
  // 使用stdarg库，获取参数信息，写入table中
}   

// 完善输入的参数
void DF_OutputInit(DF_TFL *table, int outputnum, ...) {
    // 使用stdarg库，获取参数信息，写入table中
}

// 完善输出的参数
void DF_Init(DF_TFL* table, int InputFNNum, ...) {
     // 使用stdarg库，获取参数信息，写入table中
}

// 数据流运行
void DF_Run (DF_TFL *table, int DF_Count) {
  //初始化线程池
  #ifdef THREADNUM
    DF_Thread_Init(table, THREADNUM, THREADNUM * 15+2000);
  #else
    DF_Thread_Init(table, 16, 200);
  #endif
  //改动
  if(DF_Count)
    for(int i=0; i<table->source_list_len; i++)
    {
      table->source_list[i].count = DF_Count;
      table->source_list[i].stop = 0;
      table->source_list[i].F->stop = 0;
    }
  else//在运行过程停止
    for(int i=0; i<table->source_list_len; i++)
    {
      table->source_list[i].count = 0;
      table->source_list[i].stop = 0;
      table->source_list[i].F->stop = 0;
    }    
  DF_Loop(table);
  // DF_Source_Init(source_data_addr, datasize, elementcount); // fixed by user
  DF_Destory_And_Update_Final_Data(table);
}

void DF_Loop(DF_TFL* table) {
    // 将table中的源主动函数全都启动
    for (int i=0; i<table->source_list_len; i++) {
        if (!table->source_list[i].stop) {
          assert (threadpool_add(table->pool, (void (*)(void *))(table->source_list[i].F->Func), 
            NULL, table->source_list[i].F->item_index)==0);

          table->source_list[i].count --;            //临时 ****用于源数据******
          if(table->source_list[i].count==0){
            table->source_list[i].stop = 1;
          }
          #ifdef DEBUG
            printf_thread_info(table);
          #endif
        }
    }
}

// 获取AD数据，返回当前是第几次运行
int DF_AD_GetData(DF_FN* F, ...){
    // 使用stdarg库，获取参数信息，写入table中
}

// 更新AD
void DF_AD_UpData(int DF_Count,DF_TFL *table, DF_FN *F,...){       
    // DFC函数运行完毕更新数据，同时判断接下去的函数是否准备好
    // 若准备好，使用threadpool_add 将函数加入运行队列，这里
    // 的判断是通过韩树节点的ready参数，通过位运算来判断，ready的
    // 每一位代表一个参数是否准备好了   
}

// 销毁函数，先更新数据，再释放资源
void DF_Destory_And_Update_Final_Data(DF_TFL* table) {

  // update to output_list
  DF_Update_output(table);

  // free FN
  DF_Destory_FN(table);

  // free source
  DF_Destory_source(table);

  // free TFL
  DF_Destory_TFL(table);
}
```


**整个DFC图运行流程大致如下**
![dfc_run_order](./pic/dfc_runtime/dfc_run_order.png "DFC运行流程")


c_printf库就是做了一下控制台输出的格式化功能，就不做解释，可以直接看代码

