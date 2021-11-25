#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
    public:
        Box(double lv, double wv, double hv) : length{lv}, width{wv}, height{hv} {}
        Box();
        virtual ~Box();

        double getLength() const { return length; }
        double getWidth() const { return width; }
        double getHeight() const { return height; }

        double volume(Box& aBox);
        operator bool() { return volume(*this); }

    protected:

    private:
        double length {1.0};
        double width {1.0};
        double height {1.0};
};

inline Box operator*(Box& aBox, unsigned int n)
{
    return Box(aBox.getLength(), aBox.getWidth(), aBox.getHeight()*n);
};

inline Box operator*(unsigned int n, Box& aBox)
{
    return Box(aBox.getLength(), aBox.getWidth(), aBox.getHeight()*n);
};

inline Box operator+(Box& aBox, Box& bBox)
{
    return Box(aBox.getLength()+bBox.getLength(),
               aBox.getWidth()+bBox.getWidth(),
               aBox.getHeight()+bBox.getHeight());
}

inline Box operator/(Box& aBox, unsigned int n)
{
    return Box(aBox.getLength()/n, aBox.getWidth()/n, aBox.getHeight()/n);
}

#endif // BOX_H
