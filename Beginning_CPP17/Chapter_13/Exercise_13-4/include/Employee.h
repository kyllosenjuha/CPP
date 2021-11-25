#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"

class Employee : public Person
{
    public:
        Employee(int age, std::string name, std::string gender, int pn) : Person(age, name, gender), personnelNumber{pn} {}
        Employee();
        virtual ~Employee();
        void who();
        int getPersonnelNumber() {return personnelNumber;}

    protected:

    private:
        int personnelNumber;
};

#endif // EMPLOYEE_H
