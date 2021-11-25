#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    public:
        Animal(std::string n, int w) : name{n}, weight{w} {};
        Animal();
        virtual ~Animal();
        void who();
        std::string getName() {return name;}
        int getWeight() {return weight;}

    protected:

    private:
        std::string name;
        int weight;
};

#endif // ANIMAL_H
