#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    public:
        Animal(std::string na, int we) : name{na}, weight{we} {}
        Animal();
        virtual ~Animal();
        std::string who();
        virtual std::string sound() = 0;
        std::string getName() {return name;};
        int getWeight() {return weight;};

    protected:

    private:
        std::string name;
        int weight;
};

#endif // ANIMAL_H
