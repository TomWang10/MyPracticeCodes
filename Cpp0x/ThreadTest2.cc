#include "../CommonInclude.h"

mutex gMutex;
condition_variable gCond;
bool IsFlush = false;

bool IsCanFulsh()
{
	return IsFlush;
}

void ThreadFunc1()
{
	while (true)
	{
		cout << "ThreadFunc1" << endl;
		{
			unique_lock<mutex> lck(gMutex);
			gCond.wait(lck, IsCanFulsh);
			cout << "after wait" << endl;
			IsFlush = false;
		}
		this_thread::sleep_for(chrono::seconds(3));	
	}
}

void ThreadFunc2()
{
	for (int i = 0; i < 5; ++i)
	{
		cout << "ThreadFunc2" << endl;
		unique_lock<mutex> lck(gMutex);
		IsFlush = true;
		gCond.notify_one();
	}
}

int main()
{
	thread t1(ThreadFunc1);
	thread t2(ThreadFunc2);
	t1.join();
	t2.join();
	return 0;
}
