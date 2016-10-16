#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width);
    double area() const;
    double perimeter() const;
    double diagonal() const;

private:
    double x,y,l,w;
};

#endif
