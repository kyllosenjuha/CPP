#include <iostream>
#define PI 3.14159265358979323846

using namespace std;

int main()
{
    double radius {};
    double area {};

    cout << "Give a radius: ";
    cin >> radius;

    area = PI * radius * radius;

    cout << "Area of circle is: " << area << endl;

    return 0;
}
