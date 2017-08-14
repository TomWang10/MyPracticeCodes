#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h> //bzero
#include <arpa/inet.h>
#include <iostream>


int main()
{
    int listenFD;
    listenFD = ::socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_port = htons(1999);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(listenFD, (sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(listenFD, 5);
    for (; ; )
    {
        int clientFD;
        struct sockaddr_in clientAddr;
        bzero(&clientAddr, sizeof(clientAddr));
        unsigned int addrLen = sizeof(clientAddr);
        if ((clientFD = ::accept(listenFD, (sockaddr *)&clientAddr, &addrLen)) > 0)
        {
            std::cout << "new client come\n";
        }
        else
        {
            std::cout << "accept error\n";
        }
    }
    return 0;
}
