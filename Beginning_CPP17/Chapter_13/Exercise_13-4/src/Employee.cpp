#include "Employee.h"

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

void Employee::who()
{
    std::cout << "name: " << this->getName() << ", " << this->getAge() << " years old, " << std::endl <<
                 "gender: " << this->getGender() << ", personnel number: " << personnelNumber << std::endl << std::endl;
}
