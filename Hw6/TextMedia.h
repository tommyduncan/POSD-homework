#ifndef TEXTMEDIA_H_INCLUDED
#define TEXTMEDIA_H_INCLUDED

#include<string>
#include "Media.h"
#include "Text.h"

using namespace std;

class TextMedia : public Media{
public:
    TextMedia(Text *t);
    double area() const;
    double perimeter() const;
    string getDescription();
    string getText();
    void accept(MediaVisitor *v);

private:
    Text *text;
};

#endif
