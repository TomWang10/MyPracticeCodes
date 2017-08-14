#include <iostream>
struct Apple {};
struct Banana {};

struct AppleTag {};
struct BananaTag {};

template <typename T> struct Tag{};
template <> struct Tag<Apple> { using type = AppleTag; };
template <> struct Tag<Banana> { using type = BananaTag; };

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
    FruitImpl::Eat<typename Tag<T>::type>::Munch(fruit);
}

int main()
{
    Apple a;
    Banana b;
    Eat(a);
    Eat(b);
    return 0;
}
