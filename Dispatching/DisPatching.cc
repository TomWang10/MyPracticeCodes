#include <iostream>
struct AppleTag {};
struct BananaTag {};
struct DefaultTag {};

struct Apple {
    using type = AppleTag;
};

struct Banana {
    using type = BananaTag;
};

struct Other {
    using type = DefaultTag;
};

namespace FruitImpl
{
    template <typename T> struct Eat 
    {
        template <typename T1>
        static void Munch(const T1&)
        {
            std::cout << "default" << std::endl;
        }
    };
    template <> struct Eat<AppleTag>
    {
        static void Munch(const Apple& )
        {
            std::cout << "bite" << std::endl;
        }
    };

    template <> struct Eat<BananaTag>
    {
        static void Munch(const Banana& )
        {
            std::cout << "peel" << std::endl;
        }
    };
}

template <typename T>
void Eat(const T& fruit)
{
    FruitImpl::Eat<typename T::type>::Munch(fruit);
}

int main()
{
    Apple a;
    Banana b;
    Other c;
    Eat(a);
    Eat(b);
    Eat(c);
    return 0;
}
