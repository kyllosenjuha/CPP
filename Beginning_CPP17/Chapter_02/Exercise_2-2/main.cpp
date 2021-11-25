#include <iostream>
#include <iomanip>
#define PI 3.14159265358979323846264338327950288

using namespace std;

int main()
{
    size_t precision {1};
    double radius {};
    double area {};

    do {
    cout << "Give radius: ";
    cin >> radius;

    area = PI*radius*radius;

    cout << "Give a precision: ";
    cin >> precision;

    cout << fixed << setprecision(precision) << "Circle area is: " << area << endl;
    } while(radius >= 0);

    return 0;
}
