#include <iostream>

using namespace std;

int main()
{
    int up_limit {1};
    int counter {1};

    do {
    cout << "Give a positive number (int): ";
    cin >> up_limit;
    if(up_limit < 1)
        cout << "You gave \"number < 1\"" << endl;
    } while(up_limit < 1);

    while(counter <= up_limit)
    {
        cout << counter*counter << ", ";
        counter += 2;
    }

    return 0;
}
