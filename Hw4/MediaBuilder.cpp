#include "MediaBuilder.h"

ShapeMediaBuilder::ShapeMediaBuilder(){
    sm = nullptr;
}

void ShapeMediaBuilder::buildShapeMedia(Shape *s){
    sm = new ShapeMedia(s);
};

void ShapeMediaBuilder::buildComboMedia(){
};

Media * ShapeMediaBuilder::getMedia() const{
    return sm;
}

/*
ShapeMedia * ShapeMediaBuilder::getShapeMedia() const{
    return sm;
}*/

ComboMediaBuilder::ComboMediaBuilder(){
    cm = nullptr;
}

void ComboMediaBuilder::buildShapeMedia(Shape *s){
    ShapeMedia *sm = new ShapeMedia(s);
    mediaIndex.push_back(sm);
    cm->add(sm);
}

void ComboMediaBuilder::buildShapeMedia(Media *m){
    cm->add(m);
}

void ComboMediaBuilder::buildComboMedia(){
    cm = new ComboMedia;
};

Media * ComboMediaBuilder::getMedia() const{
    return cm;
}

/*
ComboMedia * ComboMediaBuilder::getComboMedia() const{
    return cm;
}*/

ShapeMedia * ComboMediaBuilder::findMedia(Shape *s){
    for(ShapeMedia *mi: mediaIndex){
        if(mi->getShape() == s)
            return mi;
    }
    return nullptr;
}
