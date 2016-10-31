#include "ShapeMedia.h"

ShapeMedia::ShapeMedia(Shape* s): shape(s) {}

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
