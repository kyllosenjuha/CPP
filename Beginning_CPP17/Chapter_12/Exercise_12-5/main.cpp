#include <iostream>
#include "Rational.h"

int main()
{
    int integer {8};
    Rational first(811, 9);
    Rational second(2, 9);

    Rational sum=first/second;
    std::cout << first << " / " << second << " = " << sum << std::endl;

    bool smaller = integer<first;
    if(smaller)
        std::cout << integer << " is smaller than " << first << std::endl;
    else
        std::cout << integer << " is not smaller than " << first << std::endl;

    std::cout << second << " : " << (double)second << std::endl;

    Rational neg=~second;
    std::cout << second << ", negate: " << neg << std::endl;

    Rational increment=second++;

    std::cout << second << ", increment: " << increment << std::endl;

    increment=increment++;
    std::cout << increment << std::endl;

    Rational sum2 = integer/second;

    std::cout << integer << " / " << second << " = " << sum2 << std::endl;

    return 0;
}
