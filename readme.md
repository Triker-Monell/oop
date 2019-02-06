#oop project

Time: 2018 Spring Semester

Project: Movie Information Collection system



##关于如何编译运行

该程序的最终开发环境为Ubuntu16.04,只适用于Linux系统等

 1.准备
   需要事先在 /tmp 目录下递归创建如下文件夹
       /tmp/infocollection
       /tmp/infocollection/data
       /tmp/infocollection/data/photos
       /tmp/infocollection/data/allphotos
   之后将git库里的所有文件(包括文件夹)放在 /tmp/infocollection 目录下即可
   (这一步也可以直接使用库里提供的zip包，直接在 /tmp 目录下解压即可
  
 2.qt相关准备
   由于程序中采用了c++ 调用 python(注意我们所使用的python版本为2.7)，因此需要自行在库中的 InfoCS.pro 进行设置
   
   原版 InfoCS.pro 中的需要修改的部分如下
   
   INCLUDEPATH += -I/usr/include/python2.7 -I/usr/include/x86_64-linux-gnu/python2.7  ..........
   LIBS += -L/usr/lib/python2.7/config-x86_64-linux-gnu -L/usr/lib -lpython2.7 -lpthread ........
   
   += 后面的内容应当根据自身电脑设置
   打开终端输入：/usr/bin/python2.7-config --cflags #得到INCLUDEPATH的内容
   打开终端输入：/usr/bin/python2.7-config --ldflags #得到LIBS的内容
   
   参考资料:https://blog.csdn.net/qq_41800188/article/details/79709452
 3.推荐qtcreator(qt5)进行编译运行
