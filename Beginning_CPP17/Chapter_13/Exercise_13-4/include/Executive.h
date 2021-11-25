#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Employee.h"

class Executive : public Employee
{
    public:
        Executive(int age, std::string name, std::string gender, int pn) : Employee(age, name, gender, pn) {}
        Executive();
        virtual ~Executive();
        void who();

    protected:

    private:
};

#endif // EXECUTIVE_H
