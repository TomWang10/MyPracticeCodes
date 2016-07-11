#include <stdio.h>

void func2(int a, int b, int c, int d)
{
    int a1 = a, a2 = 2;
}

/*
void func1(int a, int b, int c, int d, int e, int f, int g)
{
    int a1 = a, a2 = b, a3 = c, a4 = d, a5 = e, a6 = f, a7 = g;
    func2(a1, a2, a3, a4);
}
*/

void func1(int a, int b)
{
    int a1 = a, a2 = b;
    func2(1, 2, 3, 4);
}

int main()
{
    func1(1, 2);
    return 0;
}

