#include <regex>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    const std::string separators {" ,;:.\"!?'\n"};
    std::string text {};
    std::string find_word {};
    std::cout << "Give me text ('#' ends):" << std::endl;
    getline(std::cin, text, '#');

    std::cout <<"Enter the word you want to replace: ";
    std::cin >> find_word;

    size_t start_index {text.find_first_not_of(separators)};

    int length_word=find_word.length();
    std::string replace_asterix(length_word, '*');

    while(start_index != std::string::npos)
    {
        size_t end_index = text.find_first_of(separators, start_index+1);
        if(end_index == std::string::npos)
        {
            end_index=text.length();
        }

        std::string tmp_str = text.substr(start_index, end_index - start_index);
        transform(tmp_str.begin(), tmp_str.end(), tmp_str.begin(), ::tolower);
        std::string tmp_find = find_word;
        transform(tmp_find.begin(), tmp_find.end(), tmp_find.begin(), ::tolower);

        if(tmp_str == tmp_find)
        {
            text.replace(start_index, end_index - start_index, replace_asterix);
        }
        start_index = text.find_first_not_of(separators, end_index+1);
    }

    std::cout << text << std::endl;

    return 0;
}
