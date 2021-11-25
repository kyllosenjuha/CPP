#ifndef COW_H
#define COW_H
#include <iostream>
#include "Animal.h"

class Cow : public Animal
{
    public:
        Cow(std::string name, int weight) : Animal(name, weight) {}
        Cow();
        virtual ~Cow();
        std::string sound() {return "ammuu";}
        std::string who();
        std::string getName() {return Animal::getName();};
        int getWeight() {return Animal::getWeight();};

    protected:

    private:
};

#endif // COW_H
