#include <iostream>
#include <string>

int plus(int a, int b) {return (a+b);};
double plus(double a, double b) {return (a+b);};
std::string plus(std::string a, std::string b) {return (a+b);};

int main()
{
    const int n {plus(3, 4)};
    const double d {plus(3.2, 4.2)};
    const std::string s {plus("he", "llo")};
    const std::string s1 {"aaa"};
    const std::string s2 {"bbb"};
    const std::string s3 {plus(s1, s2)};

    std::cout << n << std::endl;
    std::cout << d << std::endl;
    std::cout << s << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    return 0;
}
