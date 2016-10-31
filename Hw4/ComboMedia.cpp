#include "ComboMedia.h"

ComboMedia::ComboMedia(){}

ComboMedia::ComboMedia(vector<Media*> m) : media(m) {}

double ComboMedia::area( ) const {
    double total = 0;
        for (Media *m: media)
            total += m->area();
    return total;
}

double ComboMedia::perimeter() const{
    double total = 0;
        for (Media *m: media)
            total += m->perimeter();
    return total;
}

void ComboMedia::accept(MediaVisitor * cmVisitor) {
    cmVisitor->comboMediaVisitor(this, true);
    for (Media *m: media)
        m->accept(cmVisitor);
    cmVisitor->comboMediaVisitor(this, false);
}

void ComboMedia::add(Media *m) {
    media.push_back(m);
}
/*
string ComboMedia::getDescription(){
    return "ComboMedia";
}
*/
