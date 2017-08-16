#include <iostream>
struct AppleTag {};
struct BananaTag {};

struct Apple {
    using type = AppleTag;
};

struct Banana {
    using type = BananaTag;
};

namespace FruitImpl
{
    template <typename T> struct Eat {};
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
    Eat(a);
    Eat(b);
    return 0;
}
