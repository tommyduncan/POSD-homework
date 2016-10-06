#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

#endif // SHAPES_H_INCLUDED
