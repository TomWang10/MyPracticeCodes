#include <stdio.h>

class TestA
{
private:
    virtual void funA() { printf("Call funA\n"); }
};

class TestB : public TestA
{

};

int main()
{
    TestB b;
    typedef void (*FUNC)(void);
    FUNC pFun = (FUNC)*((int *)(*(int *)(&b)) + 0);
    pFun();
    return 0;
}
