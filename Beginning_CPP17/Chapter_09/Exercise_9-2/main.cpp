#include <iostream>

template<typename T> T larger(T a, T b);

int main()
{
    const auto a_string = "A", z_string = "Z";
    std::cout << "Larger of " << a_string << " and " << z_string
    << " is " << larger(a_string, z_string) << std::endl;
    return 0;
}

template<typename T> T larger(T a, T b)
{
    return a > b ? a : b;
}
