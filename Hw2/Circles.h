#ifndef CIRCLES_H_INCLUDED
#define CIRCLES_H_INCLUDED

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const {return 3.14 * r * r;}
    double perimeter() const {return 2 * r * 3.14;}
private:
    double cx,cy,r;
};

#endif
