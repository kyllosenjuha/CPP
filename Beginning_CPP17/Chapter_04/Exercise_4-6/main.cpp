#include <iostream>

using namespace std;

int main()
{
    int number {};

    cout << "Give a number (int): ";
    cin >> number;

    cout << (number <= 20 ? "Number is 20 or less." : (number > 20 && number <= 30 ?
    "Number is greater than 20 but not greater than 30." : (number > 30 && number <= 100 ?
    "Number is greater than 30 but not exceeding 100." : "Number is greater than 100."))) << endl;

    return 0;
}
