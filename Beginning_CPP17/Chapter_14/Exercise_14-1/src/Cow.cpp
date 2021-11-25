#include "Cow.h"

Cow::Cow()
{
    //ctor
}

Cow::~Cow()
{
    //dtor
}

std::string Cow::who()
{
    return Animal::getName();
}
