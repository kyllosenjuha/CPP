#include <iostream>
#include <vector>

int askNumber();
bool isPrimeNumber(int my_number);
std::vector<int> createNaturalVec(int lessOrEqual, int start=1);
std::vector<int> createPrimeVec(std::vector<int> my_vec);
void printVec(std::vector<int> my_vect);

int main()
{
    int i_number=askNumber();
    std::vector<int> my_vec = createNaturalVec(i_number);
    std::vector<int> myPrime_vec = createPrimeVec(my_vec);
    printVec(myPrime_vec);

    return 0;
}

int askNumber()
{
    int my_number {};
    std::cout << "Gime me a number: ";
    std::cin >> my_number;
    return my_number;
}

bool isPrimeNumber(int my_number)
{
    bool isPrime {true};

    for(int test_num {2}; test_num<my_number; ++test_num)
    {
        if(my_number % test_num == 0)
        {
            isPrime=false;
            break;
        }
    }

    return isPrime;
}

std::vector<int> createNaturalVec(int lessOrEqual, int start)
{
    std::vector<int> tmp;

    for(int number=start; number<=lessOrEqual; ++number)
        tmp.push_back(number);

    return tmp;
}

std::vector<int> createPrimeVec(std::vector<int> my_vec)
{
    std::vector<int> tmp;

    for(auto x : my_vec)
    {
        if(isPrimeNumber(x))
            tmp.push_back(x);
    }

    return tmp;
}

void printVec(std::vector<int> my_vect)
{
    int counter {};

    for(auto x : my_vect)
    {
        counter++;
        std::cout << x << ", ";

        if(counter % 10 == 0)
            std::cout << std::endl;
    }
}
