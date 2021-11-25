#include <iostream>
//#include <iterator>
#include <cmath>

int main()
{
    int my_array_size {};
    float sum {};
    float result {};

    std::cout << "Give me array size (int): ";
    std::cin >> my_array_size;

    float* p_my_array;
    p_my_array = new float [my_array_size];

    for(int index {}; index < my_array_size; ++index)
    {
        *p_my_array = 1.0/(((float)index+1.0)*((float)index+1.0));
        p_my_array++;
    }

    p_my_array -= my_array_size;

    for(int index {}; index < my_array_size; ++index)
    {
        sum += *p_my_array;
        p_my_array++;
    }

    result = sqrt(6*sum);

    std::cout << "Result: " << result << std::endl;

    p_my_array=nullptr;
    delete p_my_array;

    return 0;
}
