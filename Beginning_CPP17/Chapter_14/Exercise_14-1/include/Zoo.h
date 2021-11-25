#ifndef ZOO_H
#define ZOO_H
#include <boost/core/demangle.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
#include "Animal.h"
#include "Sheep.h"
#include "Dog.h"
#include "Cow.h"

class Zoo : public Sheep, public Dog, public Cow
{
    public:
        Zoo();
        virtual ~Zoo();
        void print(std::vector<std::shared_ptr<Sheep>> szoo);
        void print(std::vector<std::shared_ptr<Dog>> dzoo);
        void print(std::vector<std::shared_ptr<Cow>> czoo);
        void print(std::vector<std::shared_ptr<Zoo>> zzoo);
        void printAnimals();
        void createZooVector(int numberOfObjects);

    protected:

    private:
        std::vector<std::shared_ptr<Sheep>> point_sheep;
        std::vector<std::shared_ptr<Dog>> point_dog;
        std::vector<std::shared_ptr<Cow>> point_cow;
        std::vector<std::shared_ptr<Zoo>> point_zoo;

};

inline std::ostream &operator<<(std::ostream &output, const std::vector<std::shared_ptr<Sheep>> point_sheep)
{
    for(int index {}; index<(int)size(point_sheep); index++)
    {
        output << point_sheep.at(index)->getName() << ", " << point_sheep.at(index)->getWeight() << ", " << point_sheep.at(index)->sound() << std::endl;
    }
    return output;
}

inline std::ostream &operator<<(std::ostream &output, const std::vector<std::shared_ptr<Dog>> point_dog)
{
    for(int index {}; index<(int)size(point_dog); index++)
    {
        output << point_dog.at(index)->getName() << ", " << point_dog.at(index)->getWeight() << ", " << point_dog.at(index)->sound() << std::endl;
    }
    return output;
}

inline std::ostream &operator<<(std::ostream &output, const std::vector<std::shared_ptr<Cow>> point_cow)
{
    for(int index {}; index<(int)size(point_cow); index++)
    {
        output << point_cow.at(index)->getName() << ", " << point_cow.at(index)->sound() << std::endl;
    }
    return output;
}

/*
inline std::ostream &operator<<(std::ostream &output, const std::vector<std::shared_ptr<Zoo>> point_zoo)
{
    Sheep sheep;
    for(int index {}; index<(int)size(point_zoo); index++)
    {
        char const* name = typeid(point_zoo.at(index)).name();
        output << boost::core::demangle(name) << ", " << typeid(sheep).name() << std::endl;
    }

    return output;
}*/
#endif // ZOO_H
