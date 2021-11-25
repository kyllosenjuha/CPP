#include <iostream>
#include <string>

std::string reverse_string(std::string my_str);


int main()
{
    std::string my_string {};
    std::string reverse_order {};

    std::cout << "Give me a string:" << std::endl;
    getline(std::cin, my_string);

    std::cout << "Your string is:" << std::endl;
    std::cout << my_string << std::endl;

    std::cout << "Reverse order is:" << std::endl;

    reverse_order=reverse_string(my_string);

    std::cout << reverse_order << std::endl;

    return 0;
}

std::string reverse_string(std::string my_str)
{
    int my_size=my_str.length();

    std::string tmp {};

    for(int index {}; index<my_size; ++index)
    {
        tmp += my_str[my_size-1-index];
    }

    return tmp;
}
