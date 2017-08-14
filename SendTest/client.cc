#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h> //bzero
#include <arpa/inet.h>
#include <iostream>
#include <errno.h>
#include <unistd.h>

const size_t  BUFFSIZE  = 1024 * 1024 * 1024;

int main()
{
    int myFD;
    myFD = ::socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_port = htons(1999);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (::connect(myFD, (sockaddr *)&serverAddr, sizeof(serverAddr)) == 0)
    {
        std::cout << "connect server ok\n";
    }
    else
    {
        std::cout << "connect server error\n";
    }
    ssize_t sendByte = 0;
    char *sendBuff = new char[BUFFSIZE];
    if ((sendByte = ::send(myFD, &sendBuff, BUFFSIZE, MSG_NOSIGNAL)) > 0)
    {
        std::cout << "send byte " << sendByte << std::endl;
    }
    else
    {
        std::cout << "send error " << errno << std::endl;
    }
    return 0;
}
