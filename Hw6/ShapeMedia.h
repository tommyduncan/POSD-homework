#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include<string>
#include "Shape.h"
#include "Media.h"
#include "Visitor.h"

using namespace std;

class ShapeMedia :public Media {
public :
    ShapeMedia(Shape* s, string name);
    void accept(MediaVisitor * smVisitor);
    double area() const;
    double perimeter() const;
    string getDescription();
    Shape *getShape();

private:
    Shape* shape;
    string mediaName;
};

#endif // SHAPEMEDIA_H_INCLUDED

