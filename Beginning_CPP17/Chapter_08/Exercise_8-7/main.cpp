#include <iostream>
#include <vector>

int fibonacci(int x);

int main()
{
    int amountOfNumbers {}, i {};
    std::vector<int> fibonacci_vec;
    std::cout << "How many Fibonacci numbers you want to create: ";
    std::cin >> amountOfNumbers;

    while(i<amountOfNumbers)
    {
        fibonacci_vec.push_back(fibonacci(i));
        i++;
    }

    std::cout << "Fibonacci series:" << std::endl;

    for(auto x : fibonacci_vec)
        std::cout << x << std::endl;

    return 0;
}

int fibonacci(int x)
{
    if((x==1)||(x==0))
        return x;
    else
    {
        return (fibonacci(x-1)+fibonacci(x-2));
    }
}
