#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

std::condition_variable gVc;
std::mutex gMutex;
bool bWaitCondition  = false;

void ThreadFunc()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::unique_lock<std::mutex> lck(gMutex);
	bWaitCondition = true;
	gVc.notify_one();
}

bool IsTrue()
{
	return bWaitCondition;
}

int main()
{
	std::thread thread1(ThreadFunc);

	std::unique_lock<std::mutex> lck(gMutex);

	while (gVc.wait_for(lck, std::chrono::seconds(3), IsTrue))
	{
		cout <<  "Jin lai le" << endl;
		bWaitCondition = false;
	}

	thread1.join();
	return 0;
}
