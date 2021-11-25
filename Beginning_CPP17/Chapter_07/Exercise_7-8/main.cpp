#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

int main()
{
    std::string temp {};
    std::string my_string {};
    int sum {};


    do {
        std::cout << "Give me a number (int), '#' ends: ";
        std::cin >> temp;
        if(temp == "#")
            break;
        else
        {
            my_string += " ";
            my_string += temp;
        }
    } while (true);

    my_string += ".";

    const std::string separators{ " ." };
    std::vector<int> numbers;
    size_t start_index { my_string.find_first_not_of(separators) };

    while(start_index != std::string::npos)
    {
        size_t end_index = my_string.find_first_of(separators, start_index + 1);
        if(end_index == std::string::npos)
            end_index = my_string.length();
        numbers.push_back(std::stoi(my_string.substr(start_index, end_index - start_index)));
        start_index = my_string.find_first_not_of(separators, end_index + 1);
    }

    std::cout << "You gave next numbers:" << std::endl;

    for(auto x : numbers)
    {
        sum += x;
        std::cout << x << ", ";
    }

    std::cout << std::endl;
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
