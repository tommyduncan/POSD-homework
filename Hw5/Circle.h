#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"
#include<string>
#include<sstream>

using namespace std;

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius);
    double area() const;
    double perimeter() const;
    string description();

private:
    double cx, cy, r;
    string desc;
};

#endif
