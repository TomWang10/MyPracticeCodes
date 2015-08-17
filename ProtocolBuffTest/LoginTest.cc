#include "Login.pb.h"
#include <iostream>

using namespace std;

int main()
{
	Test::RetLogin msgLogin;
	msgLogin.set_type("101");
	msgLogin.set_jymm("123123");
	msgLogin.set_sjhm("13001234567");
	msgLogin.set_sblx(11);
	msgLogin.set_user_id("123456789123456789123456789");
	msgLogin.set_yybdm("12345");

	int length = msgLogin.ByteSize();
	std::cout << "Length: " << length << std::endl;
	char *buf = new char[length];
	msgLogin.SerializeToArray(buf, length);

	Test::RetLogin msgLogin1;
	msgLogin1.ParseFromArray(buf, length);
	std::cout << "type: " << msgLogin1.type() << std::endl;
	std::cout << "jymm: " << msgLogin1.jymm() << std::endl;
	std::cout << "sjhm: " << msgLogin1.sjhm() << std::endl;
	std::cout << "sblz: " << msgLogin1.sblx() << std::endl;
	std::cout << "user_id: " << msgLogin1.user_id() << std::endl;
	std::cout << "yybdm: " << msgLogin1.yybdm() << std::endl;
	std::cout << "syspm1: " << msgLogin1.syspm1() << std::endl;
	return 0;
}
