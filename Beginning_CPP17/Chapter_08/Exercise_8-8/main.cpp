#include <iostream>

double power(double x, int n);

int main()
{
    double number {}, result {};
    int potency{};
    std::cout << "Give me a number (double): ";
    std::cin >> number;
    std::cout << "Give me a power (int): ";
    std::cin >> potency;

    result=power(number, potency);

    std::cout << number << " ^ " << potency << " = " << result << std::endl;
    return 0;
}

double power(double x, int n)
{
    if(n==0)
        return 1.0;
    else
    if(n > 0)
    {
        if(n % 2 == 0)
            return power(x, n/2) * power(x, n/2);
        else
            return x * power(x, n-1);
    }
    else
    {
        return 1.0/power(x, -n);
    }
}
