#include "Lion.h"

Lion::Lion()
{
    //ctor
}

Lion::~Lion()
{
    //dtor
}

void Lion::who()
{
    std::cout << "Lion class, name: " << this->getName() << ", weight: " << this->getWeight() << std::endl;
}
