#ifndef COMBOMEDIA_H_INCLUDED
#define COMBOMEDIA_H_INCLUDED

#include<vector>
#include "Media.h"
#include "Visitor.h"

using namespace std;

class ComboMedia : public Media {
public:
    ComboMedia(vector<Media*> m);
    double area() const;
    double perimeter() const;
    void accept(MediaVisitor * cmVisitor);
    void add(Media *m);

private:
    vector<Media*> media;
};

#endif
