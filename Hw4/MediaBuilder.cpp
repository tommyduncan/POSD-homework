#include "MediaBuilder.h"

ShapeMediaBuilder::ShapeMediaBuilder(){
    sm = nullptr;
}

void ShapeMediaBuilder::buildShapeMedia(Shape *s){
    sm = new ShapeMedia(s);
};

void ShapeMediaBuilder::buildComboMedia(){
};

ShapeMedia * ShapeMediaBuilder::getShapeMedia() const{
    return sm;
}

ComboMediaBuilder::ComboMediaBuilder(){
    cm = nullptr;
}

void ComboMediaBuilder::buildShapeMedia(Shape *s){
    cm->add(new ShapeMedia(s));
}

void ComboMediaBuilder::buildShapeMedia(Media *m){
    cm->add(m);
}

void ComboMediaBuilder::buildComboMedia(){
    cm = new ComboMedia;
};

ComboMedia * ComboMediaBuilder::getComboMedia() const{
    return cm;
}
