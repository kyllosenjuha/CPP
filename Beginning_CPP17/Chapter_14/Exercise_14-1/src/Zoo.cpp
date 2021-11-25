#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Zoo.h"

Zoo::Zoo()
{
    //ctor
}

Zoo::~Zoo()
{
    //dtor
}

void Zoo::createZooVector(int numberOfObjects)
{
    srand((unsigned) time(0));

        std::shared_ptr<Sheep> sp;
        std::shared_ptr<Dog> dp;
        std::shared_ptr<Cow> cp;
        std::shared_ptr<Zoo> zp;

    for(int index {}; index<numberOfObjects; index++)
    {
        int randomNum = (rand() % 3);

        sp = std::make_shared<Sheep>(Sheep("Pete", 150));
        dp = std::make_shared<Dog>(Dog("Dog", randomNum));
        cp = std::make_shared<Cow>(Cow("Cow", randomNum));

        switch(randomNum)
        {
            case 0:
                zp = std::static_pointer_cast<Zoo>(sp);
                point_zoo.push_back(zp);
                point_sheep.push_back(sp);
                break;

            case 1:
                zp = std::static_pointer_cast<Zoo>(dp);
                point_zoo.push_back(zp);
                point_dog.push_back(dp);
                break;

            case 2:
                zp = std::static_pointer_cast<Zoo>(cp);
                point_zoo.push_back(zp);
                point_cow.push_back(cp);
                break;

            default:
                break;
         }
    }
}

void Zoo::printAnimals()
{
    Zoo::print(point_sheep);
    Zoo::print(point_dog);
    Zoo::print(point_cow);
    Zoo::print(point_zoo);
}

void Zoo::print(std::vector<std::shared_ptr<Sheep>> szoo)
{
    std::cout << "Sheeps..." << std::endl;
    for(auto x : szoo)
        std::cout << "Address: " << x << std::endl;

    std::cout << szoo << std::endl;
}

void Zoo::print(std::vector<std::shared_ptr<Dog>> dzoo)
{
    std::cout << "Dogs..." << std::endl;
    for(auto x : dzoo)
        std::cout << "Address: " << x << std::endl;

    std::cout << dzoo << std::endl;
}

void Zoo::print(std::vector<std::shared_ptr<Cow>> czoo)
{
    std::cout << "Cows..." << std::endl;
    for(auto x : czoo)
        std::cout << "Address: " << x << std::endl;

    std::cout << czoo << std::endl;
}

void Zoo::print(std::vector<std::shared_ptr<Zoo>> zzoo)
{
    std::cout << "Zoos..." << std::endl;
    for(auto x : zzoo)
        std::cout << "Address: " << x << std::endl;

    //std::cout << zzoo << std::endl;
}
