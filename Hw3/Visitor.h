#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

#include<string>

using namespace std;

class ShapeMedia;
class ComboMedia;
class MediaVisitor {
public:
    virtual void shapeMediaVisitor(ShapeMedia *sm) = 0;
    virtual void comboMediaVisitor(ComboMedia *cm) = 0;
    string getTrack();

protected:
    string track;
};

class AreaVisitor : public MediaVisitor {
    void shapeMediaVisitor(ShapeMedia *sm);
    void comboMediaVisitor(ComboMedia *cm);
};

class PerimeterVisitor : public MediaVisitor {
    void shapeMediaVisitor(ShapeMedia *sm);
    void comboMediaVisitor(ComboMedia *cm);
};

#endif
