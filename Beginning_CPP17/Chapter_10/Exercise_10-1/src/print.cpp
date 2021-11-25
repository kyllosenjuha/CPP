#include "print.h"
#include "print_this.h"
#include "print_that.h"

#include <iostream>

void print(std::string_view str)
{

    calls++;

    std::cout << str << std::endl;
}

//int calls = 0;

