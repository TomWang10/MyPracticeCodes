#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	std::time_t time_now = std::time(NULL);
	std::cout << std::localtime(&time_now) << std::endl;
	return 0;
}
