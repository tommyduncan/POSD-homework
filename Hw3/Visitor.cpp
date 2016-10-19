#include<sstream>
#include<string>
#include "Visitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

string MediaVisitor::getTrack(){
    return track;
}

void AreaVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    stringstream ss;
    ss << sm->area();
    string shapeArea = ss.str().substr(0, 5);
    track = track + shapeArea + " ";
}

void AreaVisitor::comboMediaVisitor(ComboMedia *cm) {
    stringstream ss;
    ss << cm->area();
    string comboArea = ss.str().substr(0, 5);
    track = track + comboArea + " ";
}

void PerimeterVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    stringstream ss;
    ss << sm->perimeter();
    string shapePerimeter = ss.str().substr(0, 5);
    track = track + shapePerimeter + " ";
}

void PerimeterVisitor::comboMediaVisitor(ComboMedia *cm) {
    stringstream ss;
    ss << cm->perimeter();
    string comboPerimeter = ss.str().substr(0, 5);
    track = track + comboPerimeter + " ";
}
