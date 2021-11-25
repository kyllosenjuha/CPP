#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string first_text {}, second_text {};
    std::string first_tmp {}, second_tmp {};

    std::cout << "Give me a first string: ";
    std::getline(std::cin, first_text);

    std::cout << "Give me a second string: ";
    std::getline(std::cin, second_text);

    first_tmp=first_text;
    second_tmp=second_text;

    first_tmp.erase(std::remove_if(first_tmp.begin(), first_tmp.end(), isspace), first_tmp.end());
    second_tmp.erase(std::remove_if(second_tmp.begin(), second_tmp.end(), isspace), second_tmp.end());

    transform(first_tmp.begin(), first_tmp.end(), first_tmp.begin(), ::tolower);
    transform(second_tmp.begin(), second_tmp.end(), second_tmp.begin(), ::tolower);

    std::sort(first_tmp.begin(), first_tmp.end());
    std::sort(second_tmp.begin(), second_tmp.end());

    if(first_tmp == second_tmp)
        std::cout << "\"" << first_text << "\" and \"" << second_text << "\" are anagrams." << std::endl;
    else
        std::cout << "\"" << first_text << "\" and \"" << second_text << "\" are not anagrams." << std::endl;

    return 0;
}
