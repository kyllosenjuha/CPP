#include <iostream>
#include "Box.h"

int main()
{
    unsigned int n {50};
    unsigned int m {15};

    Box original(2.5, 3.8, 4.35);
    Box zeroBox(0, 0.01, 10.0);

    original = original/m;
    Box multBox = n*original;

    std::cout << "Original: (" << original.getLength() << ", " << original.getWidth() << ", " << original.getHeight() << ")" << std::endl;
    std::cout << "multiplied Height by " << n << ": (" << multBox.getLength() << ", " << multBox.getWidth() << ", " << multBox.getHeight() << ")" << std::endl;

    if(zeroBox)
        std::cout << "zeroBox: nonzero volume" << std::endl;
    else
        std::cout << "zeroBox: zero volume" << std::endl;

    return 0;
}
