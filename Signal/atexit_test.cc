#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void ExitFunc(void)
{
	std::cout << "ExitFunc" << std::endl;
}

// 在atexit(f)调用之前被静态分配的对象的析构函数将在f()的调用之后被调用，
// 在一个atexit(f)调用之后建立的这种对象析构函数将在f()的调用之前被调用

int main()
{
	atexit(ExitFunc);
	getchar();
	return 0;
}
