#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>

std::vector<int> askGrades();
void printFive(std::vector<int> vec);
double calculateAverage(std::vector<int> vec);
double calculateMedian(std::vector<int> vec);
double calculateStandardDeviation(std::vector<int> vec);
double calculateVariance(double deviation);

int main()
{
    std::vector<int> my_grades = askGrades();

    for(auto x : my_grades)
        std::cout << x << ", ";

    std::cout << std::endl << std::endl;

    printFive(my_grades);

    double average = calculateAverage(my_grades);
    double median = calculateMedian(my_grades);
    double deviation = calculateStandardDeviation(my_grades);
    double variance = calculateVariance(deviation);

    std::cout << "Average is: " << average << std::endl;
    std::cout << "Median is: " << median << std::endl;
    std::cout << "Deviation is: " << deviation << std::endl;
    std::cout << "Variance is: " << variance << std::endl;

    return 0;
}

std::vector<int> askGrades()
{
    int grade {};
    std::vector<int> grades;

    while(true)
    {
        std::cout << "Give me a grade between [0-100] (-1 ends): ";
        std::cin >> grade;
        if(grade == -1)
            break;
        else
        if(grade >= 0 && grade <= 100)
            grades.push_back(grade);
        else
            std::cout << "Grade has to be between [0-100]." << std::endl;
    }

    std::sort(begin(grades), end(grades));

    return grades;
}

void printFive(std::vector<int> vec)
{
    int vec_size = (int)size(vec);

    std::array<int, 5> tmp_lowest {}, tmp_highest {} ;


    if(vec_size <= 5)
    {
        for(int i {}; i<vec_size; ++i)
        {
            tmp_highest[i] = vec[vec_size-1-i];
            tmp_lowest[i] = vec[i];
        }
    }
    else
    {
        for(int i {}; i<(int)size(tmp_highest); ++i)
        {
            tmp_highest[i] = vec[vec_size-1-i];
        }
        for(int i {}; i<(int)size(tmp_lowest); ++i)
        {
            tmp_lowest[i] = vec[i];
        }
    }

    std::cout << (vec_size <= 5 ? vec_size : 5) << " highest grades were:" << std::endl;

    for(int i {}; i<(int)size(tmp_highest); ++i)
    {
        std::cout << tmp_highest[i] << ", ";
    }

    std::cout << std::endl;

    std::cout << (vec_size <= 5 ? vec_size : 5) << " lowest grades were:" << std::endl;

    for(int i {}; i<(int)size(tmp_lowest); ++i)
    {
        std::cout << tmp_lowest[i] << ", ";
    }

    std::cout << std::endl;
}

double calculateAverage(std::vector<int> vec)
{
    double average {};
    double sum {};

    for(auto x : vec)
        sum += double(x);

    average=sum/(double)size(vec);

    return average;
}

double calculateMedian(std::vector<int> vec)
{
    double median = {};
    int size_vec {(int)size(vec)};

    if(size_vec % 2 != 0)
        median = (double)vec[size_vec/2];
    else
        median = ((double)vec[size_vec/2] + (double)vec[(size_vec/2) - 1])/2.0;

    return median;
}

double calculateStandardDeviation(std::vector<int> vec)
{
    double deviation {};
    int vec_size=(int)size(vec);
    double mean = calculateAverage(vec);
    double sum {};

    for(int i {}; i<vec_size; ++i)
    {
        sum += pow((vec[i] - mean), 2);
    }

    deviation = std::sqrt((1.0/(double)vec_size)*sum);

    return deviation;

}

double calculateVariance(double deviation)
{
    return deviation*deviation;
}
