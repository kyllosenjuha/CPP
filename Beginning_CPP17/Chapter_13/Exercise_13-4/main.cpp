#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Executive.h"
#include <iostream>
#include <vector>

void generatePersons()
{
    std::vector<Employee> employee;
    std::vector<Executive> executive;

    employee.push_back(Employee(44, "Juha Kyllonen", "male", 29101976));
    employee.push_back(Employee(41, "Matti Kyllonen", "male", 23081979));
    employee.push_back(Employee(65, "Pauli Kyllonen", "male", 14091955));
    employee.push_back(Employee(64, "Sointu Kyllonen", "female", 12021957));
    employee.push_back(Employee(42, "Mika Kyllonen", "male", 11111978));

    executive.push_back(Executive(60, "Pekka Johtaja", "male", 12121960));
    executive.push_back(Executive(52, "Neiti Paallikko", "female", 16101968));
    executive.push_back(Executive(40, "Team leader", "female", 11011980));
    executive.push_back(Executive(35, "Ryhman vetaja", "male", 10061985));
    executive.push_back(Executive(80, "Emeritus professori", "male", 24121940));

    std::cout << "These are Employees:" << std::endl << std::endl;
    for(auto x : employee)
        x.Employee::who();

    std::cout << "These are Executives:" << std::endl << std::endl;
    for(auto x : executive)
        x.Executive::who();
}


int main()
{
    generatePersons();
    return 0;
}
