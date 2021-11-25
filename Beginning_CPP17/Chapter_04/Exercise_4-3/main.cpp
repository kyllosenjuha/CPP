#include <iostream>

using namespace std;

void read_and_test_number(double*);
void test_number(double*);

int main()
{
    double number{1};
    double* p_number {&number};

    read_and_test_number(p_number);

    return 0;
}

void read_and_test_number(double* p_num)
{
    do {
    cout << "Give number between [1, 100] (double): ";
    cin >> *p_num;

    if(*p_num < 1.0 || *p_num > 100)
        cout << "You give wrong number." << endl;
    } while(*p_num < 1.0 || *p_num > 100);

    test_number(p_num);
}

void test_number(double* p_num)
{
    if(*p_num > 50)
        cout << *p_num << " is greater than 50." << endl;
    else
        if(*p_num < 50)
            cout << *p_num << " is less than 50." << endl;
        else
            cout << *p_num << " is equal to 50." << endl;
}
