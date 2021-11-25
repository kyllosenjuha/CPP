#include "Animal.h"
#include <iostream>

Animal::Animal()
{
    //ctor
}

Animal::~Animal()
{
    //dtor
}

void Animal::who()
{
        std::cout << "Base class, name: " << name << ", weight: " << weight << std::endl;
}
