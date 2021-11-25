#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "Animal.h"

class Dog : public Animal
{
    public:
        Dog(std::string name, int weight) : Animal(name, weight) {}
        Dog();
        virtual ~Dog();
        std::string sound() {return "hau hau";}
        std::string getName() {return Animal::getName();};
        int getWeight() {return Animal::getWeight();};

    protected:

    private:
};

#endif // DOG_H
