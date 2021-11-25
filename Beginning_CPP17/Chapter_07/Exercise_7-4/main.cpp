#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string first_text {}, second_text {};
    std::string tmp_first {}, tmp_second {};

    std::cout << "Give me a first text: ";
    std::cin >> first_text;

    std::cout << "Give me a second text: ";
    std::cin >> second_text;

    tmp_first=first_text;
    tmp_second=second_text;

    transform(tmp_first.begin(), tmp_first.end(), tmp_first.begin(), ::tolower);
    transform(tmp_second.begin(), tmp_second.end(), tmp_second.begin(), ::tolower);

    std::sort(tmp_first.begin(), tmp_first.end());
    std::sort(tmp_second.begin(), tmp_second.end());

    if(tmp_first == tmp_second)
        std::cout << "\"" << first_text << "\" and \"" << second_text << "\" are anagrams." << std::endl;
    else
        std::cout << "\"" << first_text << "\" and \"" << second_text << "\" are not anagrams." << std::endl;
    return 0;
}
