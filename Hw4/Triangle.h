#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"

using namespace std;

class Triangle : public Shape{
    public:
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
        bool isTriangle() const;
        double area() const;
        double perimeter() const;

    private:
        double a, b, c, s;
};

#endif // TRIANGLES_H_INCLUDED
