#include <iostream>
#include <limits>

using namespace std;

int main()
{
    double d_array[] {1.5, -40.9, 120.15, -10, 68, 590, 1200, -9999.89, 121.902, 1.23e+30};
    double *p_array {&d_array[0]};

    cout << "min (double): " << numeric_limits<double>::min() << endl;
    cout << "max (double): " << numeric_limits<double>::max() << endl;

    for(size_t i=0; i<size(d_array); ++i)
    cout << "adress: " << p_array+i << ", value: " << *(p_array+i) << endl;

    return 0;
}
