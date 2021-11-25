#include <iostream>
#include <vector>

void createFibonacciSeries(int amount);

int main()
{
    int amountOfFibonacci {};
    std::cout << "How many fibonacci numbers you want to create: ";
    std::cin >> amountOfFibonacci;

    createFibonacciSeries(amountOfFibonacci);

    return 0;
}

void createFibonacciSeries(int amount)
{
    std::vector<int> fibonacci;

    for(int index {}; index < amount; ++index)
    {
        if(index == 0)
            fibonacci.push_back(0);
        if(index == 1)
            fibonacci.push_back(1);
        if(index > 1)
            fibonacci.push_back(fibonacci[index-1] + fibonacci[index-2]);
    }

    std::cout << "Fibonacci series with for-loop:" << std::endl;

    for(auto x : fibonacci)
        std::cout << x << std::endl;

}
