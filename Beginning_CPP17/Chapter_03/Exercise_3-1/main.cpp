#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void set_column_widths(string base_number, size_t first_column_width, size_t second_column_width);

int main()
{
    int number {};
    int inverted {};
    int twos_complement {};

    cout << "Give integer: ";
    cin >> number;

    inverted = ~number;
    twos_complement = inverted + 1;

    set_column_widths("hex", 8, 10); cout << number;
    set_column_widths("hex", 8, 10); cout << inverted;
    set_column_widths("hex", 8, 10); cout << twos_complement << endl;

    set_column_widths("dec", 5, 13); cout << number;
    set_column_widths("dec", 5, 13); cout << inverted;
    set_column_widths("dec", 5, 13); cout << twos_complement << endl;

    return 0;
}

void set_column_widths(string base_number="hex", size_t first_column_width=0, size_t second_column_width=0)
{
    if(base_number == "hex" || base_number == "dec")
    {
        cout << showbase << internal;

        cout << (base_number == "hex" ? hex : dec);
        cout << setfill(' ') << setw(first_column_width) << ' ';
        cout << (base_number == "hex" ? setfill('0') : setfill(' '));
        cout << setw(second_column_width) << right;
    }
}
