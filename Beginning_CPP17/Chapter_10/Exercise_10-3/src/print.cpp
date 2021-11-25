#include "print.h"

#include <iostream>

namespace print1 {
    void print(std::string_view str)
    {
        std::cout << "namespace: print1, " << str << std::endl;
    }
}

namespace print2 {
    void print(std::string_view str)
    {
        std::cout << "namespace: print2, " << str << std::endl;
    }
}
