#include "Integer.h"

Integer::Integer()
{
    count++;
    printCount();
    number=0;
    std::cout << "Object is created.\n";
}

Integer::Integer(int a)
{
    count++;
    printCount();
    number=a;
    std::cout << "Object is created.\n";
}

Integer::Integer(const Integer& integer) : number {integer.number}
{
    count++;
    printCount();
    std::cout << "Copy constructor called.\n";
}

Integer::~Integer()
{
    count--;
    printCount();
}

int compareRef(int a, Integer& integer)
{
    if(a < integer.number)
        return -1;
    else
    if(a == integer.number)
        return 0;
    else
        return 1;
}

int compare(int a, Integer integer)
{
    if(a < integer.number)
        return -1;
    else
    if(a == integer.number)
        return 0;
    else
        return 1;
}

void Integer::printCount()
{
    std::cout << "printCount: " << count << std::endl;
}

int Integer::count {};
