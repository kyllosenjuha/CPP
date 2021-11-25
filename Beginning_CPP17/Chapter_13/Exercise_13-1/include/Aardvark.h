#ifndef AARDVARK_H
#define AARDVARK_H
#include <iostream>
#include "Animal.h"

class Aardvark : public Animal
{
    public:
        Aardvark(std::string name, int weight) : Animal(name, weight) {}
        Aardvark();
        virtual ~Aardvark();
        void who();

    protected:

    private:
};

#endif // AARDVARK_H
