#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string text {};
    int sum {};
    std::cout << "Give me numbers separated by spaces (# ends):" << std::endl;
    std::getline(std::cin, text, '#');

    const std::string separators{ " \n" };
    std::vector<std::string> numbers_str;
    std::vector<int> numbers;

    size_t start_index { text.find_first_not_of(separators) };

    while(start_index != std::string::npos)
    {
    size_t end_index = text.find_first_of(separators, start_index + 1);
    if(end_index == std::string::npos)
        end_index = text.length();
    numbers_str.push_back(text.substr(start_index, end_index - start_index));
    start_index = text.find_first_not_of(separators, end_index + 1);
    }

    for(auto x : numbers_str)
    {
        numbers.push_back(std::stoi(x));
    }

    std::cout << "Numbers are:" << std::endl;

    for(auto x : numbers)
        std::cout << x << ", ";

    for(auto x : numbers)
        sum += x;

    std::cout << std::endl << "Sum of these numbers is: " << sum << std::endl;

    return 0;
}
