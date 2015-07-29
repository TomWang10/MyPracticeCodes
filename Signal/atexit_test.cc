#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void ExitFunc();

// 在atexit(f)调用之前被静态分配的对象的析构函数将在f()的调用之后被调用，
// 在一个atexit(f)调用之后建立的这种对象析构函数将在f()的调用之前被调用
//
class Test
{
public:
	Test(): mInt(10)
	{
		atexit(ExitFunc);
	}
	~Test()
	{
		std::cout << "In ~Test" << std::endl;
	}

	volatile int		mInt;
};

Test gTest;


void ExitFunc(void)
{
	std::cout << "ExitFunc" << std::endl;
	std::cout << "Visit Test.mInt: " << gTest.mInt << std::endl;
}

int main()
{
	getchar();
	return 0;
}
