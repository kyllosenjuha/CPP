#include <iostream>
#include "Animal.h"
#include "Lion.h"
#include "Aardvark.h"

int main()
{
    Lion lion("Leo", 400);
    Aardvark aardvark("Algernon", 50);

    lion.Animal::who();
    lion.Lion::who();

    aardvark.Animal::who();
    aardvark.Aardvark::who();

    return 0;
}
