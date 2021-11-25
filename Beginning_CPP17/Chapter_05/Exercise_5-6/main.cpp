#include <iostream>
#include <vector>
#include <exception>

using namespace std;

int main()
{
    std::vector<int> my_vector;
    int elements {}, columns {};

    std::cout << "How many elements you want to create to your vector (int):  ";
    std::cin >> elements;

    for(int index{}; index<elements; index++)
    {
        try {
        my_vector.push_back(index);
        }
        catch(std::bad_alloc& ba)
        {
            std::cerr << "Bad alloc exception caused by: " << ba.what() << std::endl;
            exit(0);
        }
    }
    for(auto x: my_vector)
    {
        if(!(x % 7 == 0 || x % 13 == 0)) {
            std::cout.width(7); std::cout << std::right << x;
            columns++;

            if(columns % 10 == 0)
                std::cout << std::endl;
        }
    }

    return 0;
}
