#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

#include<string>
#include "Rectangle.h"

using namespace std;

class Text{
public:
    Text(Rectangle boundingbox, string text);
    double area();
    double perimeter();
    string description();
    string getText();

private:
    Rectangle *rec;
    string desc, context;
};

#endif
