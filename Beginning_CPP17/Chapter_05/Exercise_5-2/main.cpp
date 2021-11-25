#include <iostream>
#include <string>

using namespace std;

int main()
{
    int number {};
    int amount_of_numbers {};
    int sum_of_numbers {};
    double average_of_numbers {};
    string more_numbers {};
    int str_int{1};

    while(str_int != 0)
    {
        cout << "More numbers? (yes=1/no=0): ";
        cin >> more_numbers;
        str_int = stoi(more_numbers);
        if(str_int == 0)
            break;
        else
        {
            cout << "Give a number (int): ";
            cin >> number;
            sum_of_numbers += number;
            amount_of_numbers += 1;
        }
    }

    average_of_numbers = (double)sum_of_numbers / (amount_of_numbers == 0 ? 1.0 : (double)amount_of_numbers);

    cout << "You gave " << amount_of_numbers << " numbers." << endl;
    cout << "Average of your numbers is: " << average_of_numbers << endl;

    return 0;
}
