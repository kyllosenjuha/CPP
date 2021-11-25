#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int numberOfElements {};
    float sum {};
    float result {};

    std::vector<float> elements;

    cout << "How many vector elements you want to create (int): ";
    cin >> numberOfElements;

    for(int index {}; index < numberOfElements; ++index)
    {
        try {
            elements.push_back(1.0/(((float)index+1)*((float)index+1)));
        } catch(std::bad_alloc& ba)
        {
            std::cerr << "Bad allocation caused by: " << ba.what() << std::endl;
            exit(0);
        }
    }

    for(auto x : elements)
        sum += x;

    result = sqrt(6*sum);
    std::cout << std::fixed;
    std::cout << std::setprecision(8);

    std::cout << "Result is: " << result;

    return 0;
}
