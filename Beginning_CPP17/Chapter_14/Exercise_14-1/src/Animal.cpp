#include "Animal.h"
#include <string>

Animal::Animal()
{
    //ctor
}

Animal::~Animal()
{
    //dtor
}

std::string Animal::who()
{
    return (this->getName() + ", " + std::to_string(this->getWeight()));
}
