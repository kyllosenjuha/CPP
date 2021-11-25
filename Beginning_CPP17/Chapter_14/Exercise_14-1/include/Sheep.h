#ifndef SHEEP_H
#define SHEEP_H
#include <iostream>
#include "Animal.h"

class Sheep : public Animal
{
    public:
        Sheep(std::string name, int weight) : Animal(name, weight) {}
        Sheep();
        virtual ~Sheep();
        std::string sound() {return "baa baa";}
        std::string getName() {return "Woolly " + Animal::getName();};
        int getWeight() {return 0.9*(double)Animal::getWeight();};

    protected:

    private:
};

#endif // SHEEP_H
