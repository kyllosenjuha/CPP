#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string text {}, text_tmp {}, letters {}, letters_tmp {};

    std::cout << "Give me text ('#' ends):" << std::endl;
    std::getline(std::cin, text);

    std::cout << "Give letters to search: ";
    std::cin >> letters;

    text_tmp=text;
    letters_tmp=letters;

    std::transform(text_tmp.begin(), text_tmp.end(), text_tmp.begin(), ::tolower);
    std::transform(letters_tmp.begin(), letters_tmp.end(), letters_tmp.begin(), ::tolower);

    const std::string separators {" ,;:.\"!?'\n"};
    std::vector<std::string> words;
    std::vector<std::string> toLowerWords;

    size_t start_index { text_tmp.find_first_not_of(separators) };

    while (start_index != std::string::npos)
    {
        size_t end_index = text_tmp.find_first_of(separators, start_index+1);
        if(end_index == std::string::npos)
            end_index=text_tmp.length();
        toLowerWords.push_back(text_tmp.substr(start_index, end_index - start_index));
        words.push_back(text.substr(start_index, end_index - start_index));
        start_index = text_tmp.find_first_not_of(separators, end_index + 1);
    }

    std::vector<std::string> right_words;

    for(int i {}; i<(int)size(words); ++i)
    {
        for(int index {}; index<(int)letters_tmp.length(); ++index)
        {
            if(toLowerWords[i][0] == letters_tmp[index])
            {
                right_words.push_back(words[i]);
                continue;
            }
        }
    }

    std::cout << "Next words begin characters you gave: " << letters << std::endl;
    for(auto x : right_words)
        std::cout << x << std::endl;

    return 0;
}
