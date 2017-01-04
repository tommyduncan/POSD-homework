#ifndef FINDVISITOR_H_INCLUDED
#define FINDVISITOR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;
class ShapeMedia;
class ComboMedia;
class Visitor {
public:
    virtual void visitShapeMedia(ShapeMedia *sm) = 0;
    virtual void visitComboMedia(ComboMedia *cm, bool start) = 0;
};

class DescriptionVisitor : public Visitor{
public:
    DescriptionVisitor (): desc(std::string("")) {}
    void visitShapeMedia(ShapeMedia *sm){
        desc += sm->getShape()->description();
    }

    void visitComboMedia(ComboMedia *cm, bool start){
        if(start){
            desc = desc + std::string("combo(");
        }
        else{
            desc = desc + std::string(")");
        }

    }
    std::string getDescription() const {return desc;}
private:
    std::string desc;
};
class NameVisitor : public Visitor{
public:
    NameVisitor() : allName(std::string("")){}
    void visitShapeMedia(ShapeMedia *sm){
        allName += sm->getShape()->getName()+" ";
    }
    void visitComboMedia(ComboMedia *cm, bool start){
        if(start){
            allName = allName + std::string("combo(");
        }
        else{
            allName = allName + std::string(")");
        }
    }
    std::string getAllName() const {return allName;}
private:
    std::string allName;
};
class FindElementVisitor : public Visitor{
public:
    FindElementVisitor(string name) : findName(name),findElement(false){}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
    bool getFindElement(){return findElement;}
private:
    Media * m;
    bool findElement;
    std::string findName;
};
void FindElementVisitor::visitShapeMedia(ShapeMedia *sm) {
    if(findName == sm->getName()){
        findElement = true;
        m = sm;}
}

void FindElementVisitor::visitComboMedia(ComboMedia *cm, bool start) {
    if(findName == cm->getName()){
        findElement = true;
        m = cm;}
}


#endif // FINDVISITOR_H_INCLUDED
