#include <iostream>

#include "Integer.h"

int main()
{
    Integer num1;
    Integer num2;
    Integer num3;
    Integer num4(10);
    Integer num5 {num4};
    num1.set(5);
    num2.set(6);
    num3.set(20);

    int a=num1.get();
    int b=num2.get();
    int c=num3.get();
    int d=num4.get();
    int e=compare(num3.get(), num4);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << "CompareRef: " << e << std::endl;

    num1.printvalue();
    num2.printvalue();
    num3.printvalue();
    num4.printvalue();
    num5.printvalue();

    Integer first(1);
    Integer second(1);
    Integer third(1);
    Integer fourth(0);

    first.multiply(5);
    first.multiply(5);
    first.multiply(5);
    first.multiply(4);

    second.multiply(5);
    second.multiply(5);
    second.multiply(6);

    third.multiply(5);
    third.multiply(7);

    fourth.add(8);

    int result {0};

    result += first.get();
    result += second.get();
    result += third.get();
    result += fourth.get();

    std::cout << "Result is: " << result << std::endl;



    return 0;
}
