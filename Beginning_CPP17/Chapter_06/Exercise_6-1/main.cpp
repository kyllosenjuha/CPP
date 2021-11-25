#include <iostream>
#include <iomanip>
#define NUMBERS 50

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
        std::cout << std::setw(4) << std::right << *(p_my_array+index);
        if((index+1) % 10 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    for(int index {}; index<NUMBERS; ++index)
    {
        std::cout << std::setw(4) << std::right << *(p_my_array+(NUMBERS-1)-index);
        if((index+1) % 10 == 0)
            std::cout << std::endl;
    }
    return 0;
}
