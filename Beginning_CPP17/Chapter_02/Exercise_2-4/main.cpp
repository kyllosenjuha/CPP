#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846264338327950288

using namespace std;

int main()
{
    double height_inch {};
    double height_in_feet {};
    double dist_feet {};
    double dist_inch {};
    double dist_in_feet {};
    double angle {};
    double height_of_tree {};

    cout << "Give height (inches): ";
    cin >> height_inch;

    height_in_feet = height_inch / 12.0;

    cout << "Give distance in feet and inches: " << endl << "feet: ";
    cin >> dist_feet;

    cout << "Give distance in feet and inches: " << endl << "inches: ";
    cin >> dist_inch;

    dist_in_feet = dist_feet + (dist_inch / 12.0);

    cout << "Give angle (degrees): ";
    cin >> angle;

    height_of_tree = height_in_feet + dist_in_feet*tan(angle * PI / 180.0);

    cout << "Height of the tree in feet is: " << height_of_tree;

    return 0;
}
