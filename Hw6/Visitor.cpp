#include "Visitor.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "TextMedia.h"

descriptionVisitor::descriptionVisitor():desc(""){}

void descriptionVisitor::shapeMediaVisitor(ShapeMedia *sm) {
    desc += sm->getDescription();
    contentName.push_back(sm->getName());
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

vector<string> descriptionVisitor::getContentName(){
    return contentName;
}

