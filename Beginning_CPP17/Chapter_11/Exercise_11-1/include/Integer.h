#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <memory>

class Integer
{
    public:

        Integer();
        Integer(int a);
        Integer(const Integer& integer);

        virtual ~Integer();

        void set(int my_num) {number = my_num;};
        int get() {return number;};
        void printvalue() {std::cout << number << std::endl;};


        void add(int a) {number += a;};
        void substract(int a) {number -= a;};
        void multiply(int a) {number *= a;};
        friend int compareRef(int a, Integer& integer);
        friend int compare(int a, Integer integer);

        static void printCount();

    protected:

    private:
        int number;
        static int count;
};

#endif // INTEGER_H
