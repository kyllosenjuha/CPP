#include <iostream>
#include <cctype>
#include <bitset>

using namespace std;

int main()
{
    char character {};
    bool is_letter {};
    bool is_vowel {};
    bool is_lower {};

    cout << "Give a character: ";
    cin >> character;

    if(isalpha(character))
    {
        is_letter=true;

        if(character == 'a' || character == 'e' || character == 'i' ||
           character == 'o' || character == 'u' || character == 'y' ||
           character == 'A' || character == 'E' || character == 'I' ||
           character == 'O' || character == 'U' || character == 'Y')
        {
            is_vowel=true;
        }

        if(islower(character))
        {
            is_lower=true;
        }
    }

    cout << (is_letter == true ? "You gave a letter." : "You gave not a letter.") << endl;
    cout << (is_vowel == true ? "You gave a vowel." : "You gave not a vowel.") << endl;
    cout << (is_lower == true ? "You gave a lowercase." : "You gave not a lowercase.") << endl;

    if(is_lower == true)
    {
        cout << "You gave a lowercase letter: " << character << endl;
        cout << "It's binary value is: ";
        cout << "0b" << bitset<8>(character);
    }
    return 0;
}
