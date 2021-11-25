#include <iostream>
#include <iomanip>
#define NUM_OF_CHARACTERS 4

using namespace std;

void read_characters(int*, char*);
void print_sum_of_chars_hex_value(int*);
void print_chars_in_reverse_order(char*);

int main()
{
    char chars[NUM_OF_CHARACTERS];
    char *pchars {chars};
    int sum_of_chars {};
    int *p_sum_of_chars {&sum_of_chars};

    read_characters(p_sum_of_chars, pchars);
    print_sum_of_chars_hex_value(p_sum_of_chars);
    print_chars_in_reverse_order(pchars);

    return 0;
}

void read_characters(int* sum_variable, char* p_chars)
{
    for(size_t i {}; i < NUM_OF_CHARACTERS; ++i)
    {
        cout << "Give character " << i + 1 << ": ";
        cin >> *(p_chars+i);
        *sum_variable += *(p_chars+i);
    }
}

void print_sum_of_chars_hex_value(int* p_sum)
{
    cout << showbase << hex << "Sum of chars (hex): " << *p_sum << endl;

}

void print_chars_in_reverse_order(char* p_chars)
{
    cout << "Chars in reverse order: ";

    for(int i {NUM_OF_CHARACTERS-1}; i >= 0; --i)
    {
        cout << *(p_chars+i);
    }

    cout << endl;
}
