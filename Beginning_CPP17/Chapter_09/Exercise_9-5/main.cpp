#include <iostream>
#include <string>

template<typename T> static T larger(T a, T b);

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int {17011983}, small_int {10};
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << larger(big_int, small_int) << std::endl;

    return 0;
}

template<typename T> static T larger(T a, T b)
{
    static int counter {0};
    counter++;
    std::cout << "counter: " << counter << std::endl;
    return a > b ? a : b;
}
