#include <iostream>

using namespace std;

int main()
{
    char characters[1000];
    int index {};

    std::cout << "Give me a string (maximum of 1000 characters):" << std::endl;
    std::cin.getline(characters, 1000);


    while(true)
    {
        if(characters[index] != '\0')
            ++index;
        else
        {
            std::cout << "You gave: " << index << " characters." << std::endl;
            break;
        }
    }

    std::cout << "Your string is in reverse order:" << std::endl;

    while(index >= 0)
    {
        std::cout << characters[index];
        index--;
    }

    return 0;
}
