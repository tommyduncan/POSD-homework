#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include<string>
#include "Visitor.h"

using namespace std;

class Media {
public :
    virtual double area() const = 0 ;
    virtual double perimeter() const = 0 ;
    virtual void accept(MediaVisitor * v) = 0;
    virtual void add(Media * m) {
        throw string("Illegal: add on media");
    }
    virtual void remove(string name){};
    virtual string getDescription(){ return "NULL";};
    virtual string getName() = 0;
};

#endif
