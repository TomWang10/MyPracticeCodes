#include <string>
#include <iostream>
#include <algorithm>


template<typename T>
class MySmartPtr
{
public:
    MySmartPtr(): ptr_(nullptr), ref_(new int(0)) { }
    MySmartPtr(T* const rhs): ptr_(rhs), ref_(new int(1)) {
        std::cout << "ref: " << *ref_ << "\n";
    }
    MySmartPtr(const MySmartPtr& rhs): ptr_(rhs.ptr_), ref_(&(++(*rhs.ref_))) {
        std::cout << "ref: " << *ref_ << "\n";
    }
    MySmartPtr& operator=(MySmartPtr rhs) {
        swap(rhs);
    }

    T* operator->() {
        return ptr_;
    }

    T& operator*() {
        *this;
    }

    void swap(MySmartPtr& rhs) {
        using std::swap;
        swap(this->ptr_, rhs.ptr_);
        swap(this->ref_, rhs.ref_);
    }

    ~MySmartPtr() {
        (*ref_)--;
        std::cout << "decrease \n";
        if (0 == *ref_) {
            delete ref_;
            delete ptr_;
            std::cout << "delete \n";
        }

    }
private:
    T* ptr_;
    int* ref_;
};

template <typename T>
void swap(MySmartPtr<T>& a, MySmartPtr<T>& b) {
    a.swap(b);
}

int main()
{
    MySmartPtr<int> ptr1(new int(1));
    auto ptr2(ptr1);
    return 0;
}
