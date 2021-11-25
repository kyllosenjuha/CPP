#include <iostream>

template<typename T> T my_clamp(T a, T b, T c);

int main()
{
    int i_my_b {10}, i_my_c {15}, i_my_a {12};
    double d_my_b {-21.58}, d_my_c{100.25}, d_my_a{110.2};

    std::cout << my_clamp(i_my_a, i_my_b, i_my_c) << std::endl;
    std::cout << my_clamp(d_my_a, d_my_b, d_my_c) << std::endl;
    return 0;
}

template<typename T> T my_clamp(T a, T b, T c)
{
    if(a < b)
        return b;
    else if(a > c)
        return c;
    else
        return a;
}
