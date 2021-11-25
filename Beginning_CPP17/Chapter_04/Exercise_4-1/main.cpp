#include <iostream>

using namespace std;
void compare(int, int);

int main()
{
    int number_a {}, number_b {};

    cout << "Give first number (int): ";
    cin >> number_a;

    cout << "Give second number (int): ";
    cin >> number_b;

    compare(number_a, number_b);

    return 0;
}

void compare(int num_a, int num_b)
{
    if(num_a == num_b)
        cout << num_a << " = " << num_b;
    else if(num_a < num_b)
            cout << num_a << " < " << num_b;
        else
            cout << num_a << " > " << num_b;
}
