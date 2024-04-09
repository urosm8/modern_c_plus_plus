#include <iostream>
#include <type_traits>

template <typename T, typename... Args>
constexpr decltype(auto) sum(T x, Args... args)
{
    if constexpr (sizeof...(args) == 0)
        return x;
    else
        return x + sum(args...);
}

template <typename T, typename... Args>
constexpr decltype(auto) min(T x, Args... args)
{
    if constexpr (sizeof...(args) == 0)
        return x;
    else
        return x < min(args...) ? x : min(args...);
}

// template <const char*,typename... Args>
// void my_printf(const char * x, Args... args)
// {
//     printf(x);
// }

int main(int argc, char const *argv[])
{

    // sum = 17.4
    std::cout << sum(2, 1.8, 3.8, 4, 5.8) << std::endl;
    // sum = 17.4
    std::cout << sum(1.8, 2, 3.8, 4, 5.8) << std::endl;

    // min = 1.1
    std::cout << min(2.2, 1.1, 4, 4, 58) << std::endl;
    // min = -58
    std::cout << min(2.2, 1.1, 4, 4, -58) << std::endl;
    // Test #1: OK
    // my_printf("Simple check\nNew line\nAgain new line\n");

    return 0;
}
