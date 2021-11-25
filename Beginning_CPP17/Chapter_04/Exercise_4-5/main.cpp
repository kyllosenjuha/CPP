#include <iostream>

using namespace std;

int main()
{
    int mice {};
    int brown {};
    int white {} ;

    do {
    cout << "How many brown mice do you have? ";
    cin >> brown;
    if(brown < 0)
        cout << "You gave negative number." << endl;
    } while(brown < 0);

    do {
    cout << "How many white mice do you have? ";
    cin >> white;
    if(white < 0)
        cout << "You gave negative number." << endl;
    } while(white < 0);

    mice = brown + white;

    cout << "You have " << mice << (mice == 1 ? " mouse" : " mice") << " in total." << endl;

    if(mice == 0)
        cout << "You have no mice." << endl;
    else
        if(mice == 1)
        {
            cout << "You have one mice." << endl << "It is a ";
            cout << (brown == 1 ? "brown" : "white") << " mouse." << endl;
        }
        else
        {
            cout << "Of the mice, " << brown;
            cout << (brown <= 1 ? " is a" : " are") << " brown";
            cout << (brown <= 1 ? " mouse." : " mice.") << endl;
        }
    return 0;
}
