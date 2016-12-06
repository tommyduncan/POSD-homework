#include "ShapeMedia.h"

ShapeMedia::ShapeMedia(Shape* s, string name): shape(s), mediaName(name) {}

void ShapeMedia::accept(MediaVisitor * smVisitor) {
    smVisitor->shapeMediaVisitor(this);
}

double ShapeMedia::area() const {
    return shape->area() ;
}

double ShapeMedia::perimeter() const {
    return shape->perimeter();
}

string ShapeMedia::getDescription(){
    return shape->description();
}

Shape * ShapeMedia::getShape(){
    return shape;
}
