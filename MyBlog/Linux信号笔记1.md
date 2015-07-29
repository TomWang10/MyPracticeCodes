
1.  **中断的系统调用**
    如果进程在执行一个低速系统调用而被阻塞期间捕捉到一个信号，则该系统调用就被中断不再继续执行。该系统调用返回错误，其error被设置为EINTR。当捕捉到某个信号的时候，被中断的是系统调用而不是函数。
    系统调用分为两类：低速系统调用和其他系统调用。低速是会使进程永远阻塞的一类系统调用，包括：
    *   在读某些类型的文件（管道、终端设备以及网络设备）时。
    *   在写上面这些类型的文件时，如果不能立即接受这些数据时。
    *   打开某些类型文件，在某种条件发生之前也可能会发生阻塞，比如等待直到调制解调器应答。
    *   pause和wait函数。
    *   某些ioctl函数。
    *   某些进程间通信函数。
    
    现在的UNIX类系统引入了某些系统调用自重启。包括：ioctl、read、readv、write、writev、wait和waitpid。
2.  **可重入的函数**
    不可重入的意思是比如当前在执行malloc的时候，发生了信号中断，而在信号中断里面又调用了malloc，这就会出现问题。下面这个表格包括了信号处理可以重入的函数：
![可重入函数](http://pic.yupoo.com/silent-hi/ENwpHX4X/GJTXg.png)
    不可重入的函数原因如下：
    *   使用了静态的数据结构
    *   调用了malloc或者free
    *   他们是标准的I/O函数(比如printf)
    **重要**：每个线程只有一个error变量,当进入信号处理程序时，有可能更改了errno的值(因为调用了可重入函数)，必须先保存errno，然后再恢复。
3.  **可靠信号术语和语义**
    在信号产生(generation)和递送(delivery)之间的时间间隔内，称信号是未决的(pending)。
    如果为进程生产一个选择为阻塞的信号，而且对该信号的动作是系统默认动作或是捕捉该信号，则信号就一直保持为未决状态，直到：
    *   该进程解除了阻塞。
    *   将些信号的动作更改为忽略。
4.  **sigprocmask函数**

        int sigprocmask(int how, const sigset_t restrict set, sigset_t restrict oset);
        // 成功返回0,出错返回-1
        // 若oset是非空指针，这么进程的当前信号屏蔽字通过oset返回。
        // 如果set是一个非空指针，则参数how指示如果修改当前信号屏蔽字
        
    ![how参数](http://pic.yupoo.com/silent-hi/ENwsp4Zb/5cJTk.png)
5.  **sigaction函数**、

            int sigaction(int signo, const struct sigaction *restrict act, struct sigaction *restrict oact);
            // 其中sigaction结构:
            struct sigaction{
            void (*sa_handler)(int);    // addr of signal hander or SIG_IGN, or SIG_DFL
            sigset_t sa_mast;           // additional signals to block
            int sa_flags;               // signal options
            void (*sa_sigaction)(int, siginfo_t *, void *);
            };
            
    
    如果更改信号动作时，如果sa_handler为一个函数的地址，则sa_mask字段的信号集在调用该信号处理函数前，都被进程屏蔽，从信号处理函数返回时，才恢复。一但设置的动作，在重新调用sigaction之前一直都是有效的。
    sa_flags字段指定对信号进行处理的各个选项:
    ![sa_flags](http://pic.yupoo.com/silent-hi/ENwIaWoQ/gp8As.png)
    
    sa_sigaction是一个替代的处理函数，当sa_flags设置为SA_SIGINFO时，使用该信息处理函数。调用方式如下:
    
        void handler(int signo, siginfo_t *info, void *context);
        
6. **sigsetjmp和siglongjmp函数**
    在信号处理函数中应该使用这两个函数，因为平常的setjmp和longjmp不保证恢复信号屏蔽字。
        
        #include <setjmp.h>
        int sigsetjmp(sigjmp_buf env, int savemask);
        void siglongjmp(sigjmp_buf env, int val);   // 一般参数sigjmp_buf为全局变量
    
    如果savemask为非0则setlongjmp会恢复信号屏蔽字。下面是使用例子。

        // 伪代码
        // main.cc
        static volatile sig_atomic_c can_jmp;
        int main()
        {
            signal(SIGUSR1, sig_usr1);  //设置信号处理函数
            if(sigsetjmp(jmpbuf, 1))
            {
                // do something
            }
            canjump = 1;
            // canjump必须在sigsetjmp之后才设置，因为有可能sigsetjmp在保存相关的环境还没有保存完成，进程就已经收到进入了信号处理函数，调用了siglongjmp,导致出错。
        }
        
        void sig_usr1(int signo)
        {
            if (canjump == 0)   // 必须进行检查。
                return ;
            // do something
            siglongjmp(jmpbuf, 1);
        }
        
7.  **sigsuspend函数**

        ing sigsuspend(const sigset_t *sigmask);
        
    将进程的信号屏蔽字设置为由sigmask指向的值。在捕捉到一个信号或发生了一个会终止该进程的信号之前，该进程被挂起。当从信号处理函数返回后，sigsuspend返回，并返回先前的进程信号屏蔽字。
    sigsuspend有两个应用:
    *   用于保存不希望被信号中断的代码临界区
            
            // 伪代码
            // 屏蔽信号
            sigpromask(SIG_BLOCK,...)
            
            // ....临界区的代码
            
            sigsuspend(&sig_mask) 等待除了sig_mask指定的信号，并返回。
            
            // 恢复屏蔽的信号
            sigpromask(SIG_SETMASK, ...)
    *   等待信号处理函数设置一个全局变量
    
            // 伪代码
            // 信号处理程序
            volatile sig_atomic_t quitflag = 0;
            void sig_process(int signo)
            {
               quitflag = 1; 
            }
            
            int main()
            {
                sigset_t zeromask;
                sigemptyset(&zeromask);
                while (quitflag == 0)
                {
                    sigsuspend(&zeromask);
                }
                // 直到sig_process信号处理函数被调用才接下来执行下面代码
                return 0;
            }
            
    
        

        
    

