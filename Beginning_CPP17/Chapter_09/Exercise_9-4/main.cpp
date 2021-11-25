#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <iterator>

#define ARRAYSIZE 256

template<typename T> int my_size(T &t);
template<typename T, typename A> int my_size(std::vector<T, A> &vect);
template<typename T> int my_size(std::array<T, ARRAYSIZE> &arr);


int main()
{

    std::vector<int> i_vect;
    std::vector<double> values;
    std::vector<float> f_values;

    std::array<int, ARRAYSIZE> i_array = { 2, 4, 6, 8, 10 };
    std::array<double, ARRAYSIZE> d_array = { 1.5, 2.7, 6.9, 5.35, 10.9, 11.2 };

    const size_t arr_size = 100;
    double d_values[arr_size] = {};

    for(size_t i {}; i<arr_size; ++i)
    {
        d_values[i]= i + 1;
    }

    values.push_back(1.5);
    values.push_back(1.25);
    values.push_back(12.95);

    i_vect.push_back(3);
    i_vect.push_back(4);

    f_values.push_back(-1.5f);
    f_values.push_back(5.5f);
    f_values.push_back(15.95f);
    f_values.push_back(0.1f);

    int d_mySize = my_size(values);
    int i_mySize = my_size(i_vect);
    int f_mySize = my_size(f_values);
    int i_arraySize = my_size(i_array);
    int d_arraySize = my_size(d_array);
    int d_fixedSize = my_size(d_values);

    std::cout << std::endl << "double vector size: " << d_mySize << std::endl;
    std::cout << "int vector size: " << i_mySize << std::endl;
    std::cout << "float vector size: " << f_mySize << std::endl;
    std::cout << "int array size: " << i_arraySize << std::endl;
    std::cout << "double array size: " << d_arraySize << std::endl;
    std::cout << "double fixed size: " << d_fixedSize << std::endl;

    return 0;
}

template<typename T, typename A> int my_size(std::vector<T, A> &vect)
{
    int index {0};
    for(typename std::vector<T, A>::const_iterator it = vect.begin(); it != vect.end(); ++it)
    {
        index++;
    }
    return index;
}

template<typename T> int my_size(std::array<T, ARRAYSIZE> &arr)
{
    int index {0};
    for(typename std::array<T, ARRAYSIZE>::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        index++;
    }

    std::cout << arr[1] << std::endl;

    return index;
}

template<typename T> int my_size(T &t)
{
    int index {0};

    for(auto it = std::begin(t); it != std::end(t); ++it)
    {
        index++;
    }

    return index;
}

