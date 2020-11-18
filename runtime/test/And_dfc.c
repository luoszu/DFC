#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <pthread.h>

#include "threadpool.h"
#include "dfc.h"
#define TIME 1000000

DF_FN DF_FN_RandBool1;
DF_FN DF_FN_RandBool2;
DF_FN DF_FN_And;
DF_FN DF_FN_PrintBool;


DF_AD DF_AD_a;
int DF_persize_a;
int DF_fanout_a = 1;

DF_AD DF_AD_b;
int DF_persize_b;
int DF_fanout_b = 1;

DF_AD DF_AD_c;
int DF_persize_c;
int DF_fanout_c = 1;



DF_TFL DF_TFL_TABLE;


void wait()
{
  for(int i=0; i<TIME; i++);
}

void RandBool1(/* DF-C function */)
{
  int DF_count;

  # 13 "And.c"
  int a;

  DF_persize_a = sizeof(a);

  int DF_FN_item_index = DF_FN_RandBool1.item_index;

  DF_SOURCE_Get_And_Update(&DF_FN_RandBool1, &DF_count);
  {
    srand((unsigned) time(((void *) 0)));
    a = rand() % 2;
    wait();

  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_RandBool1, &a, DF_persize_a);

}


void RandBool2(/* DF-C function */)
{
  int DF_count;

  int b;

  DF_persize_b = sizeof(b);

  int DF_FN_item_index = DF_FN_RandBool2.item_index;

  DF_SOURCE_Get_And_Update(&DF_FN_RandBool2, &DF_count);
  {
    srand((unsigned) time(((void *) 0)));
    b = rand() % 2;
    wait();
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_RandBool2, &b, DF_persize_b);

}


void And(/* DF-C function */)
{
  int b;

  DF_persize_b = sizeof(b);

  int a;

  DF_persize_a = sizeof(a);

  int c;

  DF_persize_c = sizeof(c);
  int DF_count;
  DF_count = DF_AD_GetData(&DF_FN_And, &b, DF_persize_b, &a, DF_persize_a);
  {
    wait();
    c = a && b;
    // printf("a:%d b:%d\n", a,b);
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_And, &c, DF_persize_c);

}


void PrintBool(/* DF-C function */)
{
  int c;
  DF_persize_c = sizeof(c);
  int DF_count;
  DF_count = DF_AD_GetData(&DF_FN_PrintBool, &c, DF_persize_c);
  {
    wait();
    if (c == 1)
      printf("true:%d\n", DF_count);
    else
      printf("false:%d\n", DF_count );
  }
  DF_AD_UpData(DF_count, &DF_TFL_TABLE, &DF_FN_PrintBool);
}


int __original_main()
{
  double time_use=0;
  struct timeval begin;
  struct timeval end;
  gettimeofday(&begin,NULL);
  DF_Run(&DF_TFL_TABLE, 5);
  gettimeofday(&end,NULL);
  time_use=(end.tv_sec-begin.tv_sec)*1000+(double) (end.tv_usec-begin.tv_usec)/1000;
  printf("time_use is %fms\n",time_use);
  return (0);
}

/* DF-C-generated main() */
int main(int argc, char **argv)
{
  DF_ADInit(&DF_AD_c, 4, DF_fanout_c);
  DF_ADInit(&DF_AD_b, 4, DF_fanout_b);
  DF_ADInit(&DF_AD_a, 4, DF_fanout_a);

  DF_FNInit1(&DF_FN_PrintBool, &PrintBool, "PrintBool", 1, &DF_AD_c);
  DF_FNInit2(&DF_FN_PrintBool, 0);
  DF_FNInit1(&DF_FN_And, &And, "And", 2, &DF_AD_b, &DF_AD_a);
  DF_FNInit2(&DF_FN_And, 1, &DF_AD_c);
  DF_FNInit1(&DF_FN_RandBool2, &RandBool2, "RandBool2", 0);
  DF_FNInit2(&DF_FN_RandBool2, 1, &DF_AD_b);
  DF_FNInit1(&DF_FN_RandBool1, &RandBool1, "RandBool1", 0);
  DF_FNInit2(&DF_FN_RandBool1, 1, &DF_AD_a);

  DF_SourceInit(&DF_TFL_TABLE, 2, &DF_FN_RandBool2, &DF_FN_RandBool1);
  DF_Init(&DF_TFL_TABLE, 4, &DF_FN_PrintBool, &DF_FN_And, &DF_FN_RandBool2, &DF_FN_RandBool1);
  DF_OutputInit(&DF_TFL_TABLE, 0);
  int DF_original_main_ret = (int) __original_main();
  return(DF_original_main_ret);
}

