#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    std::string my_string {};
    std::string number {}, temp {};
    int sum {};
    std::vector<int> numbers;

    std::cout << "Give me ints separated by space (# = end):" << std::endl;
    std::getline(std::cin, my_string, '#');

    std::stringstream ss{ my_string };

    size_t pos=0;
    while(ss >> number)
    {
        int i = std::stoi(number, &pos);
        if (pos == number.size())
        {
            numbers.push_back(i);
        }
    }

    std::cout << std::endl << "You gave next numbers:" << std::endl;

    for(auto x : numbers)
    {
        sum += x;
        std::cout << x << ", ";
    }

    std::cout << "Sum is: " << sum << std::endl;


    return 0;
}
