#include<math.h>
#include "Rectangle.h"

Rectangle::Rectangle(double ulcx, double ulcy, double length, double width){
    x = ulcx;
    y = ulcy;
    l = length;
    w = width;
}

double Rectangle::area() const {
    return l * w;
}

double Rectangle::perimeter() const {
    return ((2 * l) + (2 * w));
}

double Rectangle::diagonal() const {
    return sqrt((l * l) + (w * w));
}

string Rectangle::description(){
    stringstream ss;

    ss << "r(" << x << " " << y << " " << l << " " << w << ")";
    desc = ss.str();

    return desc;
}
