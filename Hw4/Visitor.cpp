#include "Visitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"

descriptionVisitor::descriptionVisitor():desc(""){}

void descriptionVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    desc += sm->getDescription();
}

void descriptionVisitor::comboMediaVisitor(ComboMedia *cm, bool flag) {
    if(flag)
        desc = desc + std::string("combo(");
    else
        desc = desc + std::string(")");
}

void descriptionVisitor::textMediaVisitor(TextMedia *tm) {
    desc += tm->getDescription();
}

string descriptionVisitor::getDescription(){
    return desc;
}
