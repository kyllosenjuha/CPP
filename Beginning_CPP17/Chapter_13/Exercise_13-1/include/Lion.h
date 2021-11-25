#ifndef LION_H
#define LION_H
#include <iostream>
#include "Animal.h"

class Lion : public Animal
{
    public:
        Lion(std::string name, int weight) : Animal(name, weight) {}
        Lion();
        virtual ~Lion();
        void who();

    protected:

    private:
};

#endif // LION_H
