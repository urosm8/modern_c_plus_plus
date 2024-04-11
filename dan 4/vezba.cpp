#include <iostream>
#include <type_traits>
#include <cstdarg>

#define my_printf(X, ...) _my_printf((X), __VA_ARGS__, NULL)

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

void _my_printf(const char *str, ...)
{

    va_list va;
    va_start(va, str);
    std::string sout = "";
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '%')
            sout += str[i++];
        else
        {
            ++i;
            double f;
            std::string strf;
            char *cptr;
            int d;
            switch (str[i])
            {
            case 's':
                cptr = va_arg(va, char *);
                if (cptr == NULL)
                {
                    sout = "";
                    std::cout << "Invalid number of arguments";
                }
                else
                    sout += cptr;
                break;
            case 'f':
                f = va_arg(va, double);
                if (f == NULL)
                {
                    sout = "";
                    std::cout << "Invalid number of arguments";
                }
                else
                    strf = std::to_string(f);
                    strf.erase(strf.find_last_not_of('0')+1,std::string::npos);
                    sout += strf;
                break;
            case 'd':
                d = va_arg(va, int);
                if (d == NULL)
                {
                    sout = "";
                    std::cout << "Invalid number of arguments";
                }
                else
                    sout += std::to_string(d);
                break;
            default:
                sout = "";
                std::cout << "Incorrect type / Invalid number of arguments";
                break;
            }
            ++i;
        }
    }
    if (sout != "")
        std::cout << sout;
    va_end(va);
}

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
    my_printf("Simple check\nNew line\nAgain new line\n", 1);
    // Test #2: Invalid number of arguments
    my_printf(" text %s, integral value %d than something %d\n", "SUCCESSFULLY", 85);
    // Test #3: Incorrect type / Invalid number of arguments
    my_printf("Some text %s, some floating point number %f again something %k\n", "45", 89.7, 56);
    // Test #4: OK
    my_printf("Some text %s, some floating point number %f again something %d\n", "45", 89.7, 56);

    return 0;
}
