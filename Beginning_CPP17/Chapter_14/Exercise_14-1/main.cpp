#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Zoo.h"
#include "Animal.h"
#include "Sheep.h"
#include "Dog.h"
#include "Cow.h"

int main()
{
    int numberOfObjects {};
    std::cout << "How many objects you want to create: ";
    std::cin >> numberOfObjects;

    Zoo zoo;
    zoo.createZooVector(numberOfObjects);
    zoo.printAnimals();

    return 0;
}

