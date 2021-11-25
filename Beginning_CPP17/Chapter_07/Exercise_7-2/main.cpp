#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

int main()
{
    std::string text {};

    std::cout << "Give me text ('#' ends):" << std::endl;
    getline(std::cin, text, '#');

    const std::string separators{ " ,;:.\"!?'\n" };
    std::vector<std::string> words;
    size_t start { text.find_first_not_of(separators) };

    while(start != std::string::npos)
    {
        size_t end_index = text.find_first_of(separators, start+1);
        if (end_index == std::string::npos)
            end_index = text.length();
        words.push_back(text.substr(start, end_index - start));
        start = text.find_first_not_of(separators, end_index + 1);
    }

    std::sort(words.begin(), words.end());

    std::vector<std::string> duplicates;
    std::vector<int> number_of_same;

    duplicates=words;
    duplicates.erase( unique( duplicates.begin(), duplicates.end() ), duplicates.end() );

    int index {};
    for(auto x : duplicates)
    {
        number_of_same.push_back(count(words.begin(), words.end(), words[index]));
        index++;
    }

    index=0;

    for(auto x : duplicates)
    {
        std::cout << std::setw(15) << std::left << x;
        std::cout << std::setw(5) << std::right << number_of_same[index];
        std::cout << ", ";
        index++;
        if(index % 3 == 0)
            std::cout << std::endl;

    }


    return 0;
}
