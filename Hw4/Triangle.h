#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"
#include<string>
#include <sstream>

using namespace std;

class Triangle : public Shape{
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
        bool isTriangle() const;
        double area() const;
        double perimeter() const;
        string description();

    private:
        double tx1, ty1, tx2, ty2, tx3, ty3;
        double a, b, c, s;
        string desc;
};

#endif // TRIANGLES_H_INCLUDED
