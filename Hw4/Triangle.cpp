#include<math.h>
#include "Triangle.h"

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
    tx1(x1), ty1(y1), tx2(x2), ty2(y2), tx3(x3), ty3(y3),
    a(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))),
    b(sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2))),
    c(sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2))),
    s((a + b + c) / 2){}

bool Triangle::isTriangle() const{
    if(a > 0 && b > 0 && c > 0 && (a + b) > c && (b + c) > a && (a + c) > b){
        return true;
    }else{
        return false;
    }
}

double Triangle::area() const{
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter() const {
    return a + b + c;
}

string Triangle::description(){
    stringstream ss;
    ss << "t(" << tx1 << " " << ty1 << " " << tx2 << " " << ty2 << " " << tx3 << " " << ty3 << ")";
    desc = ss.str();

    return desc;
}
