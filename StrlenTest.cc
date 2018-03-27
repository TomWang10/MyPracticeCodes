#include <cassert>
#include <iostream>

int Mystrlen(const char* src) {
    const char* eos = src;
    while (*eos++);
    return (eos - src - 1);
}

char* Mystrcpy(char* dst, const char* src) {
    char *ret = dst;
    while ((*dst++ = *src++));
    return ret;
}

char* Mystrcat(char *dst, const char* src) {
    char *ret = dst;
    while (*dst++);
    while ((*dst++ = *src++));
    return ret;
}

int main()
{
    char *c1 = new char[10];
    const char *c2 = "12345";
    std::cout << Mystrlen(c1) << std::endl;
    std::cout << Mystrlen(c2) << std::endl;
    std::cout << Mystrcpy(c1, c2) << std::endl;
    std::cout << Mystrcat(c1, c2) << std::endl;
    return 0;
}
