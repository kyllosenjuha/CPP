#include <iostream>

using namespace std;

int main()
{
    int inches {};
    int foot {};

    cout << "Give a integer number (inches): ";
    cin >> inches;

    foot = inches / 12;
    inches = inches % 12;

    cout << inches << "is: " << foot << " feet and " << inches << " inches." << endl;
    return 0;
}
