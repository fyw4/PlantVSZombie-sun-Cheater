# PlantVSZombie-sun-Cheater
使用C语言修改植物大战僵尸阳光值。

**准备工具：**

1.cheat engine：https://www.cheatengine.org/

2.Visual Studio 2010

3.植物大战僵尸

**修改阳光值原理：**

我们打开的每一个程序中，存储数据的内存地址都会发生改变，但是程序的基址和偏移不会变。所谓基址，可以简单理解为不会随程序运行的起始时间和环境改变的地址，即全局数据区的数据的地址。 所以，对于游戏，我们关闭再启动，存放游戏关键值的变量的基址不变。

通过CE查找得知太阳值的基址0x006A9EC0，一级偏移0x768，二级偏移0x5560。

具体查找基址方法请参考：https://blog.csdn.net/wangqingchuan92/article/details/83036960

**运行截图：**

![image](https://img-blog.csdn.net/2018101417082530?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dhbmdxaW5nY2h1YW45Mg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)


**版本记录：**

2018.8.19 初版完成 V1.0

**标星次数：**

[![Stargazers over time](https://starchart.cc/fyw4/PlantVSZombie-sun-Cheater.svg)](https://starchart.cc/fyw4/PlantVSZombie-sun-Cheater)
