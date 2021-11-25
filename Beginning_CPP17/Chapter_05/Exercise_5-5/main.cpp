#include <iostream>

using namespace std;

int main()
{
    char characters[1000];
    char reverce_order[1000];

    int index {};
    int ind {};

    std::cout << "Give me a string (maximum of 1000 characters):" << std::endl;
    std::cin.getline(characters, 1000);


    for(; characters[index] != '\0'; )
    {
        ++index;
    }

    std::cout << "You gave: " << index << " characters." << std::endl;

    for(ind = index; index >= 0; --index)
    {
        reverce_order[ind-index] = characters[index];
    }

    std::cout << "Your string is in reverse order:" << std::endl;

    while(index <= ind)
    {
        std::cout << reverce_order[index];
        index++;
    }

    return 0;
}
