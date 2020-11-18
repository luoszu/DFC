# DFC

### **v0.1**

数据流通用C语言(Dataflow C language, DFC)是由深圳大学高性能计算研究所，罗秋明实验室开发的，旨在提供通用的数据流编程语言。

## 使用方法
### DFC编译器安装
```makefile
./configure --prefix="安装路径"
make
make install
```
如果configure和gen_version文件没有权限，则运行chmod +x configure/gen_version赋予运行权限

### 利用DFC编译器将DFC代码转换为标准C代码
```
安装路径/bin/ompicc  -k  -v  -s -g    -I"path-to-dfc" -I"path-to-threadpool"  "program-in-dfc"
```

### 编译选项
```
-k 保留中间文件
-v 输出编译信息
-s 生成的代码可以记录调度信息
-g 绘制DAG
```

#### 更多细节将会在后续时间补充

# DFC

### **v0.1**

Dataflow C language,  short for DFC, is developed by the laboratory in High Performance Computing Center, Shenzhen University, directed by Qiuming Luo. DFC aims at providing a general language for data flow programming.

## USAGE
### install the DFC compiler
```makefile
./configure --prefix="installation-path"
make
make install
```
If the configure or the gen_version has no permission, run
```makefile
chmod +x configure/gen_version
```
### Code  Transformation
```
installation-path/bin/ompicc  -k  -v  -s -g    -I"path-to-dfc" -I"path-to-threadpool"  "program-in-dfc"
```
### OPTIONS
```
-k keep the media files
-v details
-s generate code with recording schedule info
-g draw the DAG
```

#### more details about DFC wii be added in a later time
