#include "First.HelloProto.pb.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	First::helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");

	int length = msg1.ByteSize();
	char *buf = new char[length];
	msg1.SerializeToArray(buf, length);

	First::helloworld msg2;
	msg2.ParseFromArray(buf, length);
	std::cout << msg2.id() << msg2.str() << std::endl;

	delete [] buf;

	return 0;
}
