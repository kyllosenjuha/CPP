#include <iostream>

using namespace std;

void read_number(int*, int);
void multiple_number(int*, int*);

int main()
{
    int number_a {1}, number_b {1};
    int* p_number_a { &number_a };
    int* p_number_b { &number_b };

    read_number(p_number_a, 1);
    read_number(p_number_b, 2);

    multiple_number(p_number_a, p_number_b);

    return 0;
}

void read_number(int* number, int name)
{
    do {
    cout << "Give " << name << ". posititive number (int): ";
    cin >> *number;

    if(*number <= 0)
        cout << "You give wrong number." << endl;
    } while(*number <= 0);
}

void multiple_number(int* p_num_a, int* p_num_b)
{
    if(*p_num_a % *p_num_b == 0)
        cout << *p_num_a << " / " << *p_num_b << " = " << *p_num_a / *p_num_b << endl;
    else
        if(*p_num_b % *p_num_a == 0)
            cout << *p_num_b << " / " << *p_num_a << " = " << *p_num_b / *p_num_a << endl;
        else
            cout << "Numbers are not multiple of the other." << endl;

}
