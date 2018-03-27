#include <string>
#include <cstring>
#include <iostream>


class MyString
{
public:

    // default construct
    MyString() : data_(new char[1]) {
        *data_ = '\0';
    }

    // construct with char*
    MyString(const char* str): data_(new char[strlen(str) + 1]) {
       strcpy(data_, str);  
    }

    // copy construct
    MyString(const MyString& str) : data_(new char[strlen(str.data_) + 1]) {
        strcpy(data_, str.data_);
    }

    // operator== with c++11
    MyString& operator=(MyString str) {
        swap(str);
        return *this;
    }

   // move construct
    MyString(MyString &&str): data_(str.data_) {
       str.data_ = nullptr; 
    }

    ~MyString() {
        delete []data_;
    }

    void swap(MyString &str) {
        std::swap(data_, str.data_);
    }

    friend std::ostream& operator<<(std::ostream & os, const MyString& str);
   // deconstruct
private:
    char * data_;
};

std::ostream& operator<<(std::ostream & os, const MyString& str) {
    os << str.data_;
}

int main()
{
    MyString a("1234");
    std::cout << a;
    return 0;
}
