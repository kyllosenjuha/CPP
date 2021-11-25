#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
    public:
        Rational(int n, int d) : num{n}, denum {d} {}
        Rational();
        virtual ~Rational();
        int getNumerator() { return num; }
        int getDenumerator() { return denum; }
        operator float() {return ((float)num / (float)denum); }
        operator double() {return ((double)num / (double)denum); }
        Rational operator++(int);
        Rational operator--(int);

    protected:

    private:
        int num;
        int denum;
};

//------------------------------------------------------------------
inline Rational operator+(Rational& first, Rational& second)
{
    return Rational(first.getNumerator()*second.getDenumerator() +
                    second.getNumerator()*first.getDenumerator(),
                    first.getDenumerator()*second.getDenumerator());
}

inline Rational operator-(Rational& first, Rational& second)
{
    return Rational(first.getNumerator()*second.getDenumerator() -
                    second.getNumerator()*first.getDenumerator(),
                    first.getDenumerator()*second.getDenumerator());
}

inline Rational operator*(Rational& first, Rational& second)
{
    return Rational(first.getNumerator()*second.getNumerator(),
                    first.getDenumerator()*second.getDenumerator());
}

inline Rational operator/(Rational& first, Rational& second)
{
    return Rational(first.getNumerator()*second.getDenumerator(),
                    first.getDenumerator()*second.getNumerator());
}
//------------------------------------------------------------------
inline Rational operator+(Rational& first, int second)
{
    return Rational(second*first.getDenumerator() + first.getNumerator(),
                    first.getDenumerator());
}

inline Rational operator-(Rational& first, int second)
{
    return Rational(first.getNumerator() - second*first.getDenumerator(),
                    first.getDenumerator());
}

inline Rational operator*(Rational& first, int second)
{
    return Rational(second*first.getNumerator(),
                    first.getDenumerator());
}

inline Rational operator/(Rational& first, int second)
{
    return Rational(first.getNumerator(),
                    second*first.getDenumerator());
}

//-------------------------------------------------------------

inline Rational operator+(int first, Rational& second)
{
    return Rational(first*second.getDenumerator() + second.getNumerator(),
                    second.getDenumerator());
}

inline Rational operator-(int first, Rational& second)
{
    return Rational(first*second.getDenumerator() - second.getNumerator(),
                    second.getDenumerator());
}

inline Rational operator*(int first, Rational& second)
{
    return Rational(first*second.getNumerator(),
                    second.getDenumerator());
}

inline Rational operator/(int first, Rational& second)
{
    return Rational(first*second.getDenumerator(),
                    second.getNumerator());
}

//-------------------------------------------------------------

inline bool operator<(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) <
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator<=(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) <=
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator>(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) >
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator>=(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) >=
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator==(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) ==
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator!=(Rational& first, Rational& second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) !=
       ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

//----------------------------------------------------

inline bool operator<(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) < (double)second)
       return true;
    else
        return false;
}

inline bool operator<=(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) <= (double)second)
       return true;
    else
        return false;
}

inline bool operator>(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) > (double)second)
       return true;
    else
        return false;
}

inline bool operator>=(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) >= (double)second)
       return true;
    else
        return false;
}

inline bool operator==(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) == (double)second)
       return true;
    else
        return false;
}

inline bool operator!=(Rational& first, int second)
{
    if(((double)first.getNumerator() / (double)first.getDenumerator()) != (double)second)
       return true;
    else
        return false;
}
//----------------------------------------------------

inline bool operator<(int first, Rational& second)
{
    if((double)first < ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator<=(int first, Rational& second)
{
    if((double)first <= ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator>(int first, Rational& second)
{
    if((double)first > ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator>=(int first, Rational& second)
{
    if((double)first >= ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator==(int first, Rational& second)
{
    if((double)first == ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

inline bool operator!=(int first, Rational& second)
{
    if((double)first != ((double)second.getNumerator() / (double)second.getDenumerator()))
       return true;
    else
        return false;
}

//----------------------------------------------------

inline Rational operator~(Rational& rational)
{
    return Rational(-rational.getNumerator(), rational.getDenumerator());
}

inline Rational operator++(Rational& rational)
{
    return Rational(rational.getNumerator() + rational.getDenumerator(),
                    rational.getDenumerator());
}

inline Rational operator--(Rational& rational)
{
    return Rational(rational.getNumerator() - rational.getDenumerator(),
                    rational.getDenumerator());
}

inline std::ostream& operator<<(std::ostream& os, Rational& rational)
{
    os << rational.getNumerator() << "/" << rational.getDenumerator();
    return os;
}
#endif // RATIONAL_H
