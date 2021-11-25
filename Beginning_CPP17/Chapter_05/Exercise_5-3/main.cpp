#include <iostream>
#include <string>

using namespace std;


int main()
{

    int amount_of_nonwhitespace {};
    int index {};
    string my_string {};
    cout << "Give a string, put '#' to end:" << endl;
    getline(cin, my_string, '#');

    do {
        if(my_string[index] == '#' || my_string[index] == '\0')
        {
            break;
        }
        else
        if(my_string[index] != ' ' && my_string[index] != '\n')
        {
            amount_of_nonwhitespace += 1;
            index += 1;
        }
        else
            index += 1;

    } while(true);

    cout << "You gave: " << amount_of_nonwhitespace << " non whitespace characters." << endl;

    return 0;
}
