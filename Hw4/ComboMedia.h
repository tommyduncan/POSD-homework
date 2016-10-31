#ifndef COMBOMEDIA_H_INCLUDED
#define COMBOMEDIA_H_INCLUDED

#include<vector>
#include<string>
#include "Media.h"
#include "Visitor.h"

using namespace std;

class ComboMedia : public Media {
public:
    ComboMedia();
    ComboMedia(vector<Media*> m);
    double area() const;
    double perimeter() const;
    void accept(MediaVisitor * cmVisitor);
    void add(Media *m);
    void remove(Media *m);
    //string getDescription();

private:
    vector<Media*> media;
};

#endif
