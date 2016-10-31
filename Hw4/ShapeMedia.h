#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include<string>
#include "Shape.h"
#include "Media.h"
#include "Visitor.h"

using namespace std;

class ShapeMedia :public Media {
public :
    ShapeMedia(Shape* s);
    void accept(MediaVisitor * smVisitor);
    double area() const;
    double perimeter() const;
    string getDescription();

private:
    Shape* shape;
};

#endif // SHAPEMEDIA_H_INCLUDED

