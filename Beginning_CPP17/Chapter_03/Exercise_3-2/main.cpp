#include <iostream>

using namespace std;

int main()
{
    double shelf_length {};
    double shelf_depth {};

    int box_side {};
    long number_of_boxes {};

    cout << "Give shelf length (double, feet): ";
    cin >> shelf_length;
    shelf_length *= 12.0;

    cout << "Give shelf depth (double, feet): ";
    cin >> shelf_depth;
    shelf_depth *= 12.0;

    cout << "Give box side (int, inches): ";
    cin >> box_side;

    number_of_boxes = (static_cast<long>(shelf_length / box_side)) * (static_cast<long>(shelf_depth / box_side));

    cout << "Number of square boxes: " << number_of_boxes;

    return 0;
}
