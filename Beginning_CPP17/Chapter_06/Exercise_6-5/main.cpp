#include <iostream>
#include <memory>
#include <cmath>

int main()
{
    float sum {}, result {};
    size_t number_of_elements {};
    std::cout << "Give me a size of array (size_t): ";
    std::cin >> number_of_elements;

    auto p_values{ std::make_unique<float[]>(number_of_elements) };
    for(size_t index{}; index<number_of_elements; ++index)
    {
        p_values[index] = 1.0/(((float)index+1)*((float)index+1));
    }

    for(size_t index {}; index<number_of_elements; ++index)
        sum += p_values[index];

    result=sqrt(6*sum);

    std::cout << "Result is: " << result << std::endl;

    return 0;
}
