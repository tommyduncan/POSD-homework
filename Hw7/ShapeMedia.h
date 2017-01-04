#ifndef SHAPEMEDIA_H_INCLUDED
#define SHAPEMEDIA_H_INCLUDED

#include "Shapes.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <cstring>

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
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
    std::string getDescription() const {return desc;}
private:
    std::string desc;
};
class NameVisitor : public Visitor{
public:
    NameVisitor() : allName(std::string("")){}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
    std::string getAllName() const {return allName;}
private:
    std::string allName;
};
class setNameVisitor : public Visitor{
public:
    setNameVisitor(string s) : now(0){
        int k = s.size();
        char strContent[k];
        strcpy(strContent, s.c_str());
        char * temps;
        temps = strtok(strContent, " {}");
        while(temps!=NULL){
            cout<<temps<<endl;
            string name(temps);
            sname.push_back(name);
            temps = strtok (NULL, " {}");
        }
    }
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
private:
    vector<string> sname;
    int now;
};
class Media;
class FindElementVisitor : public Visitor{
public:
    FindElementVisitor(string name) : findName(name),findElement(false){}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
    bool getFindElement(){return findElement;}
    Media * getMedia(){return m;}
private:
    Media * m;
    bool findElement;
    std::string findName;
};

class putLoadDataVisitor : public Visitor{
public:
    putLoadDataVisitor(vector<Media *> *showList) {list_m = showList;}
    void visitShapeMedia(ShapeMedia *sm);
    void visitComboMedia(ComboMedia *cm, bool start);
private:
    vector<Media *> *list_m;
};
class Media {
public :
    virtual double area() const = 0 ;
    virtual double perimeter() const = 0;
    virtual void acceptSV(setNameVisitor * sv) = 0;
    virtual void acceptFV(FindElementVisitor * fv) =0;
    virtual void acceptNV(NameVisitor * nv) =0;
    virtual void accept(DescriptionVisitor * dv) = 0;
    virtual void acceptPLDV(putLoadDataVisitor * pdlv) = 0;

    virtual void add(Media * m) {
        throw std::string("Illegal: add on media");
    }
    virtual void removeMedia(Media* m){
        throw std::string("Illegal: remove on media");
    }
    virtual string getName() = 0;
};

class ShapeMedia :public Media {
private:
    Shape* shape ;
public :
    ShapeMedia( Shape* s ): shape(s) {}
    virtual void accept(DescriptionVisitor * dv) {
        dv->visitShapeMedia(this);
    }
    void acceptNV(NameVisitor * nv) {
        nv->visitShapeMedia(this);
    }
    void acceptSV(setNameVisitor * sv){
        sv->visitShapeMedia(this);
    }
    void acceptFV(FindElementVisitor * fv){
        fv->visitShapeMedia(this);
    }
    void acceptPLDV(putLoadDataVisitor * pdlv) {
        pdlv->visitShapeMedia(this);
    }
    double area() const { return shape->area() ; }
    double perimeter() const { return shape->perimeter() ; }
    string getName(){
        return shape->getName();
    }
    void setName(string name){shape->setName(name); }
    Shape * getShape()const {return shape;}
};

class ComboMedia : public Media {
private:
    string name;
    std::vector<Media*> media;
public:
    ComboMedia( std::vector<Media*> m ) : media(m) {}
    ComboMedia () {}
    double area() const {
        double total =0;
            for (Media *m: media)
                total += m->area();
        return total;}
    double perimeter() const
    {
        double total =0;
        for (Media *m: media)
            total += m->perimeter();
        return total;
    }
    void acceptFV(FindElementVisitor * fv) {
        fv->visitComboMedia(this, true);
        for (Media *m: media)
            m->acceptFV(fv);
        fv->visitComboMedia(this, false);}
    void acceptSV(setNameVisitor * sv){
        sv->visitComboMedia(this, true);
        for (Media *m: media)
            m->acceptSV(sv);
        sv->visitComboMedia(this, false);}
    void acceptNV(NameVisitor * nv) {
        nv->visitComboMedia(this, true);
        for (Media *m: media)
            m->acceptNV(nv);
        nv->visitComboMedia(this, false);}
    void accept(DescriptionVisitor * dv) {
        dv->visitComboMedia(this, true);
        for (Media *m: media)
            m->accept(dv);
        dv->visitComboMedia(this, false);}
    void acceptPLDV(putLoadDataVisitor * pdlv) {
        pdlv->visitComboMedia(this, true);
        for (Media *m: media)
            m->acceptPLDV(pdlv);
        pdlv->visitComboMedia(this, false);
    }
    void add (Media *m) {media.push_back(m);}
    void removeMedia(Media * m){
        for(vector<Media*>::const_iterator it = media.begin(); it != media.end(); ++it) {
            if(*it == m) {
                //cout<<m->getName()<<endl;
                //delete *it;
                media.erase(it);
                return;}
            else {(*it)->removeMedia(m);}
        }
    }

    void setName(string name){this->name = name;}
    string getName(){return name;}
};

void DescriptionVisitor::visitShapeMedia(ShapeMedia *sm) {
    desc += sm->getShape()->description();
}

void DescriptionVisitor::visitComboMedia(ComboMedia *cm, bool start) {
    if(start){
        desc = desc + std::string("combo(");
    }
    else{
        desc = desc + std::string(")");
    }

}
void NameVisitor::visitShapeMedia(ShapeMedia *sm) {
    allName += sm->getShape()->getName()+" ";
}
void NameVisitor::visitComboMedia(ComboMedia *cm, bool start){
    if(start){
        allName = allName + cm->getName() + std::string("{");
    }
    else{
        allName = allName + std::string("}");
    }
}

void setNameVisitor::visitShapeMedia(ShapeMedia *sm) {
    sm->setName(sname[now]);
    now++;
}
void setNameVisitor::visitComboMedia(ComboMedia *cm, bool start) {
    if(start){
        cm->setName(sname[now]);
        now++;}
}
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
void putLoadDataVisitor::visitShapeMedia(ShapeMedia *sm){
    bool _find = false;
    for(int i=0;i<list_m->size();i++){
        if( list_m->at(i)->getName() == sm->getName() ){
            sm->setName(list_m->at(i)->getName()+"_1");
        }
    }
    list_m->push_back(sm);
}
void putLoadDataVisitor::visitComboMedia(ComboMedia *cm, bool start){
    if(start){
        bool _find = false;
        for(int i=0;i<list_m->size();i++){
            if(list_m->at(i)->getName() == cm->getName()){
                cm->setName(list_m->at(i)->getName()+"_1");
            }
        }
        list_m->push_back(cm);
    }
}
class MediaBuilder {
public:
    MediaBuilder (): combo(0) {}
    void buildComboMedia() {combo = new ComboMedia;}
    void buildShapeMedia(Shape *s) {
        if(!combo)
            throw std::string("null point ex") ;
        combo->add(new ShapeMedia(s));
    }
    void buildAddComboMedia(ComboMedia * cm){
        combo->add(cm);
    }
    ComboMedia * getComboMedia() const {return combo;}
private:
    ComboMedia * combo;
};

class MediaDirector{
public :
    void setMediaBuilder(std::stack<MediaBuilder *> *mbs){
        mb = mbs;
    }

    void concrete(std::string content)
    {
        int ptrIndex = 0;
        int visitDepth = 0;
        while(ptrIndex < content.length())
        {
            if(content[ptrIndex] == 'c' &&
               content[ptrIndex + 1] == 'o' &&
               content[ptrIndex + 2] == 'm' &&
               content[ptrIndex + 3] == 'b' &&
               content[ptrIndex + 4] == 'o' &&
               content[ptrIndex + 5] == '(')
            {
                visitDepth++;
                ptrIndex += 6;
                mb->push(new MediaBuilder());
                mb->top()->buildComboMedia();
            }
            else if(content[ptrIndex] == 'r' &&
               content[ptrIndex + 1] == '(')
            {
                ptrIndex += 2;

                int endIndex = ptrIndex;
                while(content[endIndex] != ')') endIndex++;
                std::string subLine = content.substr(ptrIndex, endIndex - ptrIndex);

                std::istringstream iss;
                iss.str(subLine);
                int x, y, l, w;
                iss >> x >> y >> l >> w;

                mb->top()->buildShapeMedia(new Rectangle(x, y, l, w));

                ptrIndex += endIndex - ptrIndex + 1;
                while(content[ptrIndex] == ' ') ptrIndex++;
            }

            else if(content[ptrIndex] == 'c' &&  content[ptrIndex + 1] == '(')
            {
                ptrIndex += 2;

                int endIndex = ptrIndex;
                while(content[endIndex] != ')') endIndex++;
                std::string subLine = content.substr(ptrIndex, endIndex - ptrIndex);

                std::istringstream iss;
                iss.str(subLine);
                int cx, cy, r;
                iss >> cx >> cy >> r;

                mb->top()->buildShapeMedia(new Circle(cx, cy, r));

                ptrIndex += endIndex - ptrIndex + 1;
                while(content[ptrIndex] == ' ') ptrIndex++;
            }
            else if(content[ptrIndex] == ')')
            {
                visitDepth--;
                ptrIndex++;
                while(content[ptrIndex] == ' ') ptrIndex++;

                if(mb->size() > 1)
                {
                    ComboMedia *cm = mb->top()->getComboMedia();
                    mb->pop();
                    mb->top()->buildAddComboMedia(cm);
                }
            }
            else
                ptrIndex++;
        }
    }
private :
    std::stack<MediaBuilder *> *mb;
};
/*
string saveFile(string name,string content){
    if(!ofstream fout(name)){
        throw std::string("Fail");
    }
    fout << content << std::endl;
    return std::string("Success save");
}*/

#endif // SHAPEMEDIA_H_INCLUDED
