#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include "Shape.h"
#include "Media.h"
#include "Visitor.h"

class ShapeMedia :public Media {
public :
    ShapeMedia(Shape* s);
    void accept(MediaVisitor * smVisitor);
    double area() const;
    double perimeter() const;

private:
    Shape* shape ;
};

#endif // SHAPEMEDIA_H_INCLUDED

