# APUE线程

1.  **线程创建**

        #include <pthread.h>
        int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void *), void *restrict arg);


    线程创建时并不保证是新创建的线程还是调用线程先运行。新线程会继承调用线程的浮点环境和信号屏蔽字，但是该线程的未决信号信被清除。
    **Note**:不能在新创建的线程中使用`pthread_create()`中的tidp参数获得线程id，因为有可能`pthread_create()`还没有返回，而新线程已经在运行了，那tidp是未初始化的状态，应该使用`pthread_self()`来获得自己的线程id。
    
2.  **线程终止**
    如果进程中的任何一个线程调用了`exit,_Exit,_exit`中的任何一个，整个进程都被会终止。如果信号的默认动作是终止进程，那整个进程也会被终止。
    单个线程可以通过下面的方式退出，而不终止整个进程:
    *   线程只是从启动例子中返回，返回值是线程的退出码。
    *   线程可以被同一进程的其他线程取消
    *   线程调用pthread_exit
        

            void pthread_exit(void *rval_ptr)
            int pthread_join(pthread_t thread, void **rval_ptr)
            
            
    进程中的其他线程可以通过调用`pthread_join`访问到rval_ptr，调用线程将一直阻塞，直到指定线程
    
    *   调用`pthread_exit`
    *   从启动例程中返回
    *   被取消。
    
    如果线程只是从它的启动例程中返回，rval_ptr将包含返回码。如果线程被取消，由rval_ptr指定的内存单元就被设置为`PTHREAD_CANCELED`。
    线程可以安排它退出时需要调用的函数，这与进程可以用`atexit`函数安装进程退出时需要调用的函数是类似的。这样的函数称为线程清理处理程序。线程可以建立多个清理处理程序。它们的执行顺序和他们的注册时的顺序相反。
            
        void pthread_cleanup_push(void (*rtn)(void *), void *arg);
        void pthread_cleanup_pop(int execute);
    
    当线程执行以下动作时调用清理函数，调用参数为arg，清理函数rtn的调用顺序由`pthread_cleanup_push`安排的。
    *   调用pthread_exit时。
    *   响应取消请求时(别的线程调用`pthread_cancel()`)
    *   用非零execute参数调用`pthread_cleanup_pop`时。
    
    如果execute参数为0,清理函数将不会被调用。无论哪一种情况，当调用`pthread_cleanup_pop`时，所有用`pthread_cleanup_push`建立的函数都会被清除。
    **Note**:请将`pthread_cleanup_push`和`pthread_cleanup_pop`配对，不然可能编译通过不了。eg:
        
        void *thread_func(void *arg)
        {
            pthread_cleanup_push();
            pthread_cleanup_push();
            
            // 这里使用pthread_exit退出从而调用清除线程
            pthread_exit();
            
            //但是这里一定要配对出现pthread_cleanup_pop
            pthread_cleanup_pop();
            pthread_cleanup_pop();
        }
    在默认情况下，线程的终止状态会保存到对该线程调用`pthread_join`，如果线程是处于**分离**状态的，线程的底层存储资源可以在线程终止时马上被收回。当线程分享时，没有办法对该线程使用`pthread_join`。使用`pthread_deteach`使线程处于分离状态。
    
3.  **线程同步**
    *   **互斥量**
        在使用互斥量之前必须进程初始化，可以把它置为常量`PTHREAD_MUTEX_INITIALIZER`(只对静态分配的互斥量)，也可以通过调用`pthread_mutex_init`初始化。如果动态分配互斥量(比如调用`malloc`)，则释放前需要调用`pthread_mutex_destroy`。
            
            int pthread_mutex_lock(pthread_mutex_t *mutex);
            int phread_mutex_trylock(pthread_mutex_t *mutex);
            int phread_mutex_unlock(pthread_mutex_t *mutex);

        如果不习惯被阻塞可以调用`phread_mutex_trylock`尝试进行加锁。如果成功返回0，如果失败返回EBUSY。
    *   **读写锁**
        读写锁可以有三种状态:
        *   读模式下加锁状态
        *   写模式下加锁状态
        *   不加锁的状态
        一次只有一个线程可以占有写模式的读写锁，但有多个线程可以同时占有读模式的读写锁,当读写锁处于读模式锁住状态时，如果有另外的线程试图以写模式加锁，读写锁通常会阻塞随后的读模式锁请求，不然会长期被读模式锁战胜，而不能处于写模式
        
            int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);
            int pthread_rwlock_destory(pthread_rwlock_t *rwlock);
            // 锁读
            int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
            // 锁写
            int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
            // 释放
            int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
            
        
4.  **条件变量**
    条件变量本身是由互斥量保护的。线程在改变条件状态前必须首先锁住互斥量，其他线程在获得互斥量之前不会察觉到这种改变，因为必须锁定互斥量以后才能计算条件。
    初始化可以有两种方式:

           PTHREAD_COND_INITALIZER
           int pthread_cond_init(pthread_cond_t *restrict cond, pthread_condattr_t *restrict attr)
           int pthread_cond_destory(pthread_cond_t *cond)
           
    使用`pthread_cond_wait`等待条件变为真，如果在给定的时间内条件不能满足，这么会生成一个代表出错码的返回变量
    
            int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex)
            int pthread_cond_timewait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex,
            const struct timespec *restrict timeout);
        
    传递给`pthread_cond_wait`的互斥量对条件进行保护，调用者把锁住的互斥量传给函数。函数把调用线程放到等待条件的线程列表上，然后对互斥量解锁，这两个操作是原子操作。`pthread_cond_wait`返回时，互斥量再次被锁住。
    `pthread_cond_signal`函数将唤醒等待该条件的某个线程，而`pthread_cond_signal`函数将唤醒等待该条件的所有线程。
    
    
    
    


