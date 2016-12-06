#include "TextMedia.h"

TextMedia::TextMedia(Text *t): text(t) {}

double TextMedia::area() const{
    return text->area();
}

double TextMedia::perimeter() const{
    return text->perimeter();
}

string TextMedia::getDescription(){
    return text->description();
}

string TextMedia::getText(){
    return text->getText();
}

void TextMedia::accept(MediaVisitor *tmVisitor){
    tmVisitor->textMediaVisitor(this);
}
