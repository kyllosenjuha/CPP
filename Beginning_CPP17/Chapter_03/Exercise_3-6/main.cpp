#include <iostream>

using namespace std;

void swapping(int&, int&);
void print_and_swap_values(int&, int&);

int main()
{
    int value_a {};
    int value_b {};

    int &value_a_ref = value_a;
    int &value_b_ref = value_b;

    cout << "Give value a (int): ";
    cin >> value_a_ref;

    cout << "Give value b (int): ";
    cin >> value_b_ref;

    print_and_swap_values(value_a_ref, value_b_ref);

    return 0;
}

void swapping(int& val_a, int& val_b)
{
    val_a = val_a + val_b;
    val_b = val_a - val_b;
    val_a = val_a - val_b;
}

void print_and_swap_values(int& val_a_print, int& val_b_print)
{
    cout << "Original: " << endl << "(" << val_a_print << ", " << val_b_print << ")" << endl;
    swapping(val_a_print, val_b_print);
    cout << "Swapped:" << endl << "(" << val_a_print << ", " << val_b_print << ")" << endl;
}
