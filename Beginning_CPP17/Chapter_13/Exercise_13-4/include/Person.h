#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    public:
        Person(int a, std::string n, std::string g) : age{a}, name{n}, gender{g} {}
        Person();
        virtual ~Person();
        int getAge() {return age;}
        std::string getName() {return name;}
        std::string getGender() {return gender;}
    protected:

    private:
        int age;
        const std::string name;
        const std::string gender;
};

#endif // PERSON_H
