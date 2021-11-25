#include "Box.h"

Box::Box()
{
    //ctor
}

Box::~Box()
{
    //dtor
}

double Box::volume(Box& aBox)
{
    return (aBox.length * aBox.width * aBox.height);
}
