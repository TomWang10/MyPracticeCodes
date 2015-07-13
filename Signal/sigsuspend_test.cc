#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t quitflag; //在信号处理函数中设置为1

// 同时处理SIGINT和SIGQUIT
static void sig_int(int signo)
{
    if (signo == SIGINT)
        printf("\ninterrupt\n");
    else if (signo == SIGQUIT)
        quitflag = 1;
}

int main(void)
{
    sigset_t newmask, oldmask, zeromask;

    if (signal(SIGINT, sig_int) == SIG_ERR)
    {
        printf("signal SIGINT error\n");
        return 0;
    }
    if (signal(SIGQUIT, sig_int) == SIG_ERR)
    {
        printf("signal SIGINT error\n");
        return 0;
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGQUIT);

    // 屏蔽SIGQUIT并保存当前的信号屏蔽字
    if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        printf("sigprocmask error\n");
        return 0;
    }

    while (quitflag == 0)
        sigsuspend(&zeromask);
    
    // 到这里SIGQUIT信号已经被处理完毕，并且被上面的sigprocmask屏蔽了。
    quitflag = 0;

    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        printf("sigprocmask error\n");
        return 0;
    }
    return 0;
}
