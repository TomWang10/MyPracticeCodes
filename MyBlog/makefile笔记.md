#复习Makefile笔记
------
之前简单的学习了几次Makefile,然后写了一个简单的通用Makefile，但因为没有频繁的折腾,又把这方面的知识给忘记了。今天记录一下，以便复习。
------
##make命令和makefile文件
**1.makefile语法**
	一个makefile文件由组依赖文系和规则构成。每个依赖关系由一个目标(即将创建的文件)和一组该目标文件所依赖的源文件组成。而规则描述如何通过这些依赖文件创建目标。
**2.make命令的选项和参数**
	*-k: 它的作用是让make命令在发现错误时仍然继续执行，而不是在检测到每一个错误时就停下来。可以利用这个选项一次性的把所有编译未通过的文件找出来。
	*-n: 直接显示接下来make要执行的步骤，而不是真正的执行。
	*-f: 指定makefile文件名，不然默认是查找makefile和Makefile。
**3.依赖关系**
	首先我们创建3个头文件:a.h、b.h、c.h和3个源文件main.cc、2.cc和3.cc来理解和学习makefile。具体的依赖情况如下:
```c++
// main.cc
#include "a.h"

// 2.cc
#include "a.h"
#include "b.h"

// 3.cc
#include "b.h"
#include "c.h"
```
	在makefile文件中,这些规则的写法是:先写目标的名称，然后紧跟着冒号，接着是空格或者tab,然后用空格或制表符tab隔开的文件列表(这些文件用于创建目标文件)前面的依赖关系在makefile里面是这样表示的:
```c++
myapp: main.o 2.o 3.o
main.o: main.cc a.h
2.o: 2.cc a.h b.h
3.o: 3.cc b.h c.h
```
	如果你想一次创建多个文件，你就要用伪目标all。比如你要创建myapp和他的说明文件myapp_1，你就可以使用all: myapp myapp_1来创建两个文件，如果你没有指定all的话，make默认生成makefile的第一个目标文件
**4.规则**
	比如上面的例子要生成3.o，就需要使用命令g++ -c 3.cc。
------
##第一个makefile: makefile1
	接下来我们具体编写上面例子中的代码文件，然后编写一个最简单的makefile。
	对于a、b、c三个头文件我们只需要生成简单的空文件就行，具体的main.cc、2.cc、3.cc代码如下：
```c++
/* main.cc */
#include <stdlib.h>
#include "a.h"

extern void function_two();
extern void function_three();

int main()
{
	function_two();
	function_three();
	return 0;
}

/* 2.cc */
#include "a.h"
#include "b.h"

void function_two()
{}

/* 3.cc */
#include "b.h"
#include "c.h"

void function_three()
{}

```
	而我们最简单的Makefile1如下:
```makefile
#最简单形式的makefile
myapp: main.o 2.o 3.o
	g++ -o myapp main.o 2.o 3.o
main.o: main.cc a.h
	g++ -c main.cc
2.o: 2.cc a.h b.h
	g++ -c 2.cc
3.o: 3.cc b.h c.h
	g++ -c 3.cc
```
	接下来我们就可以使用make -f Makefile1来生成我们的目标文件myapp了。
------
##第二个makefile: makefile2 使用宏的makefile
	宏的作用就是makefile里面的文件依赖和规则可以使用宏来代替，一旦你需要修改，就只需要修改宏定义的部分。使用MACRONAME=value来定义宏，引用宏就使用$(MACRONAME)。下面是使用宏的makefile2:
```makefile
#带宏的makefile
all: myapp

# 指定编译器
CC = g++

# 设置引用的头文件目录
INCLUDE = .

# 设置调试模式的一些选项
CFLAGS = -g -Wall -ansi

# 设置发布模式的一些选项
#CFLAGS = -O -Wall -ansi

myapp: main.o 2.o 3.o
	$(CC) -o myapp main.o 2.o 3.o

main.o: main.cc a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.cc

2.o: 2.cc a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.cc

3.o: 3.cc b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.cc

```
make会将相应的$(CC)、$(CFLAGS)等替换对应的宏定义，相当于c语言的宏。make也有一些内置的宏，下面是4个常用的内置宏:
*$?：当前目标所依赖的文件列表中比当前目标文件还要新的文件
*$@：当前目标的名字
*$<：当前依赖文件的名字
*$*：不包括后缀名的当前依赖文件的名字
还有两个有用的特殊字符会经常碰到,它们出现在命令之前：
*-：告诉make命令忽略所有错误。比如你想创建一个目标，又想忽略任何错误(比如目录已存在)
*@：告诉make命令不要显示在标准输出上。
------
##第三个makefile: makefile3 有多个目标的makefile
```makefile
#新增加clean选项删除不需要的目标文件，增加一个install选项来将编译成功的应用程序安装到另一个目录下
all: myapp

# 指定编译器
CC = g++

# 设置安装在哪一个目录
INSTDIR = /usr/local/bin

# 设置引用的头文件目录
INCLUDE = .

# 设置调试模式的一些选项
CFLAGS = -g -Wall -ansi

# 设置发布模式的一些选项
#CFLAGS = -O -Wall -ansi

myapp: main.o 2.o 3.o
	$(CC) -o myapp main.o 2.o 3.o

main.o: main.cc a.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.cc

2.o: 2.cc a.h b.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 2.cc

3.o: 3.cc b.h c.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c 3.cc

#clean 没有给clean目标定义任何的依赖关系,所以该目标总被认为是过时的,执行make命令时,如果指定目标为clean，对应的规则(-rm main.o 2.o 3.o)总是被执行
clean:
	# 减号的含义就是让make命令忽略rm命令的执行结果,就是说如果目标文件不存在,clean也会执行成功
	-rm main.o 2.o 3.o

#目标install依赖于myapp，所以make命令知道它必须先创建myapp,然后才执行其他命令.
#由于安装myapp要分几个shell命令完成，并且make命令在执行规则时会针对每一个规则调用一个新的shell.所以必须在上面每行代码的结尾加上一个反斜杠.让所有的命令做为一个整体传给一个shell执行。
#这个命令以@符号开关，表示在执行这些规则之前不会在标准输出上显示命令本身
install: myapp
	@if [ -d $(INSTDIR) ]; \
		then \
		cp myapp $(INSTDIR); \
		chmod a+x $(INSTDIR)/myapp;\
		chmod og-w $(INSTDIR)/myapp;\
		echo "Installed in $(INSTDIR)";\
	else \
		echo "Sorry, $(INSTDIR) does not exist"; \
	fi
```
最后：这些只是最最基础的makefile知识。如果我有更深入的了解再来分享吧。如果有什么错误的地方请留言给我。我会非常开心的。
