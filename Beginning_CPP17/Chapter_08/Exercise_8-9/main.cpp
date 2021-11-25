#include <iostream>

double power(double x, int n);
double mult(double x, int n);

static int counter {};

int main()
{
    double number {}, result {};
    int potency{};
    std::cout << "Give me a number (double): ";
    std::cin >> number;
    std::cout << "Give me a power (int): ";
    std::cin >> potency;

    result=mult(number, potency);

    std::cout << number << " ^ " << potency << " = " << result << std::endl;
    std::cout << "Multiplication executed: " << counter << " times.";

    return 0;
}

double power(double x, int n)
{
    double tmp {};

    if(n==0)
        return 1.0;
    else
    if(n > 0)
    {
        if(n % 2 == 0)
        {
            tmp=mult(x, n/2);
            return tmp*tmp;
        }
        else
        {
            tmp=mult(x, n-1);
            return x * tmp;
        }
    }
    else
    {
        return 1.0/mult(x, -n);
    }
}

double mult(double x, int n)
{
    counter++;
    std::cout << "power(" << x << ", " << n << "), was called: " << counter << " times." << std::endl;
    return power(x, n);
}

