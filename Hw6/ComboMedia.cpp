#include "ComboMedia.h"

ComboMedia::ComboMedia(string name) : mediaName(name) {}

ComboMedia::ComboMedia(vector<Media*> m, string name) : media(m), mediaName(name) {}

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

void ComboMedia::remove(string name){
    int index = 0;
    for(unsigned int i = 0; i < media.size(); i++){
        if(name == media[i]->getName()){
                index = i;
                break;
        }else{
            index = -1;
        }
    }
    media.erase(media.begin() + index);
}

string ComboMedia::getName(){
    return mediaName;
}
