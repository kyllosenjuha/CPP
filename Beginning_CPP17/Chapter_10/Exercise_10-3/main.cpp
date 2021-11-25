#include <iostream>
#include <string_view>

#include "print.h"
#include "print_that.h"
#include "print_this.h"

//#define DO_THIS

int main()
{
    std::string_view str_this {"Print this"};
    std::string_view str_that {"Print that"};

    #ifdef DO_THIS
    print_this(str_this);
    #endif // DO_THIS

    #ifndef DO_THIS
    print_that(str_that);
    #endif

    return 0;
}
