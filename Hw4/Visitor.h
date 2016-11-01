#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include<string>
#include<sstream>

using namespace std;

class ShapeMedia;
class ComboMedia;
class TextMedia;
class MediaVisitor {
public:
    virtual void shapeMediaVisitor(ShapeMedia *sm) = 0;
    virtual void comboMediaVisitor(ComboMedia *cm, bool flag) = 0;
    virtual void textMediaVisitor(TextMedia *tm) = 0;
    //string getTrack();
};

class descriptionVisitor : public MediaVisitor{
public:
    descriptionVisitor();
    void shapeMediaVisitor(ShapeMedia *sm);
    void comboMediaVisitor(ComboMedia *cm, bool flag);
    void textMediaVisitor(TextMedia *tm);
    string getDescription();
private:
    string desc;
};

#endif
