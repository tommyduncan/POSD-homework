#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius);
    double area() const;
    double perimeter() const;

private:
    double cx, cy, r;
};

#endif
