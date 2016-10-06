#ifndef RECTANGLES_H_INCLUDED
#define RECTANGLES_H_INCLUDED

#include<math.h>

class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width){}
    double area() const {return l * w;}
    double perimeter() const {return ((2 * l) + (2 * w));}
private:
    double x,y,l,w;
};

#endif // RECTANGLES_H_INCLUDED
