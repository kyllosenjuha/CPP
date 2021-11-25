#include <iostream>
#include <array>

using namespace std;

int main()
{
    std::array<unsigned long long, 93> fibonacci_series {1, 1};

    for(int index {2}; index < 93 ; ++index)
    {
        fibonacci_series[index] = fibonacci_series[index-1] + fibonacci_series[index-2];
    }

    for(auto x : fibonacci_series)
        std::cout << x << std::endl;
    return 0;
}
