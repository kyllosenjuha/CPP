#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name {};
    int age {};

    cout << "Give your name: ";
    getline(cin, name);

    do
    {
    cout << "Give your age: ";
    cin >> age;

    if(age < 0)
        cout << "You give negative age!" << endl;

    } while(age < 0);

    cout << "Your name is: " << name << endl << "Your age is: " << age << " year." << endl;

    return 0;
}
