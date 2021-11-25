#include "Rational.h"

Rational::Rational()
{
    //ctor
}

Rational::~Rational()
{
    //dtor
}

Rational Rational::operator++(int)
{
    return ++*this;
}

Rational Rational::operator--(int)
{
    return --*this;
}
