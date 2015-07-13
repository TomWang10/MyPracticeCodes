#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void AbortProcess(int signo)
{
    printf("start AbortProcess\n");
    return;
}

int main()
{
    struct sigaction action;
    action.sa_handler = AbortProcess;

    if (sigaction(SIGABRT, &action, NULL) < 0)
    {
        printf("sigaction error\n");
        return 0;
    }
    abort();
    printf("不会执行了吗？\n");
    return 0;
}
