#include <iostream>

using namespace std;

int main()
{
    double money_total {};
    double original_money {};
    int dollars {};
    int quarters {};
    int dimes {};
    int nickels {};
    int pennies {};

    bool valid_money {};

    do {
    cout << "Give me amount of money between $0 and $10 (double): ";
    cin >> money_total;

    if(money_total >= 0 && money_total <= 10)
        {
        valid_money = true;
        }
    else
        {
        valid_money = false;
        cout << "You gave invalid money." << endl;
        }
    } while(!valid_money);

    original_money = money_total;

    dollars = (int)money_total;
    money_total -= (double)dollars;
    quarters = (int)(money_total / 0.25);
    money_total -= 0.25*(double)quarters;
    dimes = (int)(money_total / 0.1);
    money_total -= 0.1*(double)dimes;
    nickels = (int)(money_total / 0.05);
    money_total -= 0.05*(double)nickels;
    pennies = (int)(money_total / 0.01);

    cout << "Amount of $" << original_money << " is:" << endl;
    cout << dollars << (dollars <= 1 ? " dollar." : " dollars.") << endl;
    cout << quarters << (quarters <= 1 ? " quarter." : " quarters.") << endl;
    cout << dimes << (dimes <= 1 ? " dime." : " dimes.") << endl;
    cout << nickels << (nickels <= 1 ? " nickel." : " nickels.") << endl;
    cout << pennies << (pennies <= 1 ? " penny." : " pennies.") << endl;

    return 0;
}
