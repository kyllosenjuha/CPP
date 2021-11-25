#include "Aardvark.h"

Aardvark::Aardvark()
{
    //ctor
}

Aardvark::~Aardvark()
{
    //dtor
}

void Aardvark::who()
{
    std::cout << "Aarddvark class, name: " << this->getName() << ", weight: " << this->getWeight() << std::endl;
}
