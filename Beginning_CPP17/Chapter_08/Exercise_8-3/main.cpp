#include <iostream>



int main(int argc, char* argv[])
{
    if(argc < 3)
        std::cout << "You have to give at least 2 arguments." << std::endl;
    else
    if(argc > 5)
        std::cout << "You have to give maximum of 4 arguments." << std::endl;
    else
    {
    for(int index {}; index < argc; ++index)
        std::cout << argv[index] << std::endl;
    }

    return 0;
}
