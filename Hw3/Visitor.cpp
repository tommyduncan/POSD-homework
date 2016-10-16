#include<sstream>
#include "Visitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

string MediaVisitor::getTrack(){
    return track;
}

void AreaVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    stringstream ss;
    ss << sm->area();
    track = track + ss.str() + " ";
}

void AreaVisitor::comboMediaVisitor(ComboMedia *cm) {
    stringstream ss;
    ss << cm->area();
    track = track + ss.str() + " ";
}

void PerimeterVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    stringstream ss;
    ss << sm->perimeter();
    track = track + ss.str() + " ";
}

void PerimeterVisitor::comboMediaVisitor(ComboMedia *cm) {
    stringstream ss;
    ss << cm->perimeter();
    track = track + ss.str() + " ";
}
