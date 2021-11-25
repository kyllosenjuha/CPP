#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
    std::string name;
    std::vector<std::string> names;
    int grade;
    std::vector<int> grades;
    double sum {}, average {};

    char more {'y'};

    while(more=='y')
    {
        std::cout << "Do you want add more names (y/n): ";
        std::cin >> more;
        if(more=='n')
            break;
        else
        {
            std::cout << "Give me first name: ";
            std::cin >> name;
            names.push_back(name);

            std::cout << "Give me a grade: ";
            std::cin >> grade;
            grades.push_back(grade);
        }
    }

    for(auto x : grades)
        sum += x;

    average=sum/grades.size();

    for(size_t index {}; index<names.size(); ++index)
    {
        std::cout << std::setw(10) << std::left << names[index] << std::setw(4) << std::left << grades[index];
        if((index+1) % 3 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl << "Average is: " << average << std::endl;


    return 0;
}
