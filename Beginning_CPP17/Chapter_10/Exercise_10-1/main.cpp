#include <iostream>
#include <string_view>
#include "print.h"
#include "print_this.h"
#include "print_that.h"

int calls {};

int main()
{
    std::string_view str_this {"Print this"};
    std::string_view str_that {"Print that"};

    print_this(str_this);
    std::cout << calls << std::endl;

    print_that(str_that);
    std::cout << calls << std::endl;

    print_this(str_this);
    std::cout << calls << std::endl;

    print_that(str_that);
    std::cout << calls << std::endl;

    return 0;
}
