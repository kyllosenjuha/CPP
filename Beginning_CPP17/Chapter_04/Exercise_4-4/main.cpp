#include <iostream>
#include <string>

using namespace std;

enum class AcademicDegree {none, associate, bachelor, professional, master, doctor};

void ask_age();
void ask_gender();
void ask_degree();
void ask_marital_status();
void ask_language_skills();
void not_valid_person();

int main()
{
    ask_age();
    ask_gender();
    ask_degree();
    ask_marital_status();
    ask_language_skills();

    cout << "You are a valid person." << endl;

    return 0;
}

void ask_age()
{
    int age {0};

    cout << "Give your age: ";
    cin >> age;

    if(!(age > 21 && age < 35))
    {
        cout << "Your age is not between 21 < age < 35." << endl;
        not_valid_person();
        exit(0);
    }
    return;
}

void ask_gender()
{
    char gender {};

    cout << "Give gender (m/f): ";
    cin >> gender;

    if(gender != 'f')
    {
        cout << "You are not female." << endl;
        not_valid_person();
        exit(0);
    }
    return;
}

void ask_degree()
{
    int i_degree {};
    AcademicDegree degree {AcademicDegree::none};

    cout << "Valid degrees are: " << endl;
    cout << "none(0), associate(1), bachelor(2), professional(3), master(4), doctor(5)" << endl;
    cout << "Give your degree (int): ";
    cin >> i_degree;

    degree = (AcademicDegree)i_degree;

    if(!((degree == AcademicDegree::bachelor) || (degree == AcademicDegree::master)))
    {
        cout << "Your degree is not bachelor's or master's degree." << endl;
        not_valid_person();
        exit(0);
    }
    return;
}

void ask_marital_status()
{
    bool married {0};

    cout << "Are you married? (yes=1, no=0): ";
    cin >> married;

    if(married == true)
    {
        cout << "You are married." << endl;
        not_valid_person();
        exit(0);
    }
    return;
}

void ask_language_skills()
{
    bool speaksHindi{0}, speaksUrdu{0};

    cout << "Do you speak Hindi? (yes=1, no=0): ";
    cin >> speaksHindi;

    cout << "Do you speak Urdu? (yes=1, no=0): ";
    cin >> speaksUrdu;

    if(!(speaksHindi == true || speaksUrdu == true))
    {
        cout << "You do not speak Hindi or/and Urdu." << endl;
        not_valid_person();
        exit(0);
    }
    return;
}

void not_valid_person()
{
    cout << "You are not a valid person." << endl;
}
