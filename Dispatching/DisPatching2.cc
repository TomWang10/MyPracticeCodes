#include <iostream>
#include <type_traits>


struct FruitTag {};
struct AppleTag : FruitTag {};
struct BananaTag : FruitTag {};
struct CoffeeTag{};

struct Apple {
    using type = AppleTag;
};
struct Banana {
    using type = BananaTag;
};
struct Coffee {
    using type = CoffeeTag;
};

namespace FruitImpl
{
    template <typename T> struct Eat {};
    template <> struct Eat<FruitTag>
    {
        template <typename T>
        static void Munch(const T&)
        {
            std::cout << "Fruit" << std::endl;
        }
    };

    template <> struct Eat<CoffeeTag>
    {
        template <typename T>
        static void Munch(const T&)
        {
            std::cout << "Coffee" << std::endl;
        }
    };

    template <typename Tag, typename BaseTag, typename... Other>
    struct TagCast
    {
        using type = typename std::conditional<
            std::is_base_of<BaseTag, Tag>::value,
            BaseTag,
            typename TagCast<Tag, Other...>::type>::type;
    };

    template <typename Tag, typename BaseTag>
    struct TagCast<Tag, BaseTag>
    {
        using type = typename std::conditional<
            std::is_base_of<BaseTag, Tag>::value,
            BaseTag,
            Tag>::type;
    };
}


template <typename T>
void Eat(const T& fruit)
{
    FruitImpl::Eat<typename FruitImpl::TagCast<typename T::type, FruitTag, CoffeeTag>::type>::Munch(fruit);
}

int main()
{
    Apple a;
    Banana b;
    Coffee c;
    Eat(a);
    Eat(b);
    Eat(c);
    return 0;
}
