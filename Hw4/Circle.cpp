#include "Circle.h"

Circle::Circle(double centerX,double centerY,double radius):cx(centerX),cy(centerY),r(radius){}

double Circle::area() const {
    return ( 3.14 * r * r );
}

double Circle::perimeter() const {
    return ( 2 * r * 3.14 );
}

string Circle::description(){
    stringstream ss;

    ss << "c(" << cx << " " << cy << " " << r << ")";
    desc = ss.str();

    return desc;
}
