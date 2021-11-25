#include <iostream>
#include <string>

#define DAYS_MIN 1
#define DAYS_MAX 31
#define MONTHS_MIN 1
#define MONTHS_MAX 12
#define JANUARY 31
#define FEBRUARY 28
#define FEBRUARY_LEAP 29
#define MARCH 31
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31
#define SEPTEMBER 30
#define OCTORBER 31
#define NOVEMBER 30
#define DECEMBER 31
#define YEARS_MIN 1000
#define YEARS_MAX 3000

void askValues(int& day, int& month, int& year);
bool validate_input(int& day, int& month, int& year);
bool isLeapYear(int& year);
void printMonth(int& month);

int main()
{
    int i_day {};
    int i_month {};
    int i_year {};

    while(true)
    {
        askValues(i_day, i_month, i_year);

        if(i_day == -1)
            break;

        bool isDayMonthYearOK = validate_input(i_day, i_month, i_year);

        if(isDayMonthYearOK == true)
        {
            std::cout << "You gave a valid day." << std::endl;

            printMonth(i_month);

            std::cout << " " << i_day << ", " << i_year << std::endl;
        }
        else
            std::cout << "Your day was not a valid." << std::endl;

    }

    return 0;
}

void askValues(int& day, int& month, int& year)
{
    std::cout << "Give me a day (" << DAYS_MIN << "-" << DAYS_MAX << "), (-1 = ends): ";
    std::cin >> day;
    if(day == -1)
        return;
    std::cout << "Give me a month (" << MONTHS_MIN << "-" << MONTHS_MAX << "): ";
    std::cin >> month;
    std::cout << "Give me a year (" << YEARS_MIN << "-" << YEARS_MAX << "): ";
    std::cin >> year;
}

bool validate_input(int& day, int& month, int& year)
{
    bool isDayValid {false};

    if(year >= YEARS_MIN && year <= YEARS_MAX)
    {

        switch(month) {
            case 1:
            if(day >= DAYS_MIN && day <= JANUARY)
            {
                isDayValid=true;
                break;
            }
            break;

            case 2:

            if(isLeapYear(year) == true)
            {
                if(day >= DAYS_MIN && day <= FEBRUARY_LEAP)
                {
                    isDayValid=true;
                    break;
                }
            }
            else
                if(day >= DAYS_MIN && day <= FEBRUARY)
                {
                    isDayValid=true;
                    break;
                }
            break;

            case 3:
            if(day >= DAYS_MIN && day <= MARCH)
            {
                isDayValid=true;
                break;
            }
            break;

            case 4:
            if(day >= DAYS_MIN && day <= APRIL)
            {
                isDayValid=true;
                break;
            }
            break;

            case 5:
            if(day >= DAYS_MIN && day <= MAY)
            {
                isDayValid=true;
                break;
            }
            break;

            case 6:
            if(day >= DAYS_MIN && day <= JUNE)
            {
                isDayValid=true;
                break;
            }
            break;

            case 7:
            if(day >= DAYS_MIN && day <= JULY)
            {
                isDayValid=true;
                break;
            }
            break;

            case 8:
            if(day >= DAYS_MIN && day <= AUGUST)
            {
                isDayValid=true;
                break;
            }
            break;

            case 9:
            if(day >= DAYS_MIN && day <= SEPTEMBER)
            {
                isDayValid=true;
                break;
            }
            break;

            case 10:
            if(day >= DAYS_MIN && day <= OCTORBER)
            {
                isDayValid=true;
                break;
            }
            break;

            case 11:
            if(day >= DAYS_MIN && day <= NOVEMBER)
            {
                isDayValid=true;
                break;
            }
            break;

            case 12:
            if(day >= DAYS_MIN && day <= DECEMBER)
            {
                isDayValid=true;
                break;
            }
            break;

            default:
            {
                isDayValid=false;
                break;
            }
        }
    }
    else
    {
        isDayValid=false;
    }

    return isDayValid;
}

bool isLeapYear(int& year)
{
    if(year % 100 == 0)
    {
        if(year % 400 == 0)
            return true;
        else
            return false;
    }
    else
        if(year % 4 == 0)
            return true;
        else
            return false;
}

void printMonth(int& i_month)
{
    std::cout << ((i_month == 1) ? "January" : "");
    std::cout << ((i_month == 2) ? "February" : "");
    std::cout << ((i_month == 3) ? "March" : "");
    std::cout << ((i_month == 4) ? "April" : "");
    std::cout << ((i_month == 5) ? "May" : "");
    std::cout << ((i_month == 6) ? "June" : "");
    std::cout << ((i_month == 7) ? "July" : "");
    std::cout << ((i_month == 8) ? "August" : "");
    std::cout << ((i_month == 9) ? "September" : "");
    std::cout << ((i_month == 10) ? "October" : "");
    std::cout << ((i_month == 11) ? "November" : "");
    std::cout << ((i_month == 12) ? "December" : "");
}
