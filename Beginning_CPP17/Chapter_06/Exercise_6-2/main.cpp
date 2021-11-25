#include <iostream>
#include <iomanip>
#define NUMBERS 100

using namespace std;

int main()
{
    int my_array[NUMBERS];
    int* p_my_array;
    p_my_array=my_array;

    for(int index {}; index<NUMBERS; ++index)
        my_array[index] = 1 + index*2;

    for(int index {}; index<NUMBERS; ++index)
    {
        std::cout << std::setw(4) << std::right << *p_my_array;
        p_my_array++;
        if((index+1) % 10 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    p_my_array=my_array+(NUMBERS-1);

    for(int index {}; index<NUMBERS; ++index)
    {
        std::cout << std::setw(4) << std::right << *p_my_array;
        p_my_array--;
        if((index+1) % 10 == 0)
            std::cout << std::endl;
    }
    return 0;
}
