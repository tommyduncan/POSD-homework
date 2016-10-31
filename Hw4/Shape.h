#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include<string>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string description(){return "Non-shape";}
};

#endif
