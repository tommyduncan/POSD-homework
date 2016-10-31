#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include<string>

using namespace std;

class ShapeMedia;
class ComboMedia;
class MediaVisitor {
public:
    virtual void shapeMediaVisitor(ShapeMedia *sm) = 0;
    virtual void comboMediaVisitor(ComboMedia *cm, bool flag) = 0;
    //string getTrack();
};

class descriptionVisitor : public MediaVisitor{
public:
    descriptionVisitor();
    void shapeMediaVisitor(ShapeMedia *sm);
    void comboMediaVisitor(ComboMedia *cm, bool flag);
    string getDescription();
private:
    string desc;
};

#endif
