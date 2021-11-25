#include <iostream>
#include <string>

template<typename A, typename B> double plus(A* a, B* b);
std::string plus(std::string* a, std::string* b);

int main()
{
    double d_a {100.25};
    double *p_a;
    p_a = &d_a;

    int i_b {12};
    int *p_b;
    p_b = &i_b;

    std::string first_string {"Juha "};
    std::string second_string {"Kyllonen"};

    std::string* p_first;
    p_first = &first_string;

    std::string* p_second;
    p_second = &second_string;


    std::cout << *p_a << " + " << *p_b << " = " << plus(p_a, p_b) << std::endl;
    std::cout << *p_first << " + " << *p_second << " = " << plus(p_first, p_second) << std::endl;
    return 0;
}

template<typename A, typename B> double plus(A* a, B* b)
{
    return (*a + *b);
}

std::string plus(std::string* a, std::string* b)
{
    std::string temp {};
    temp += *a;
    temp += *b;

    return temp;
}


