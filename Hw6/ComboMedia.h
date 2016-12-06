#ifndef COMBOMEDIA_H_INCLUDED
#define COMBOMEDIA_H_INCLUDED

#include<vector>
#include<string>
#include "Media.h"
#include "Visitor.h"

using namespace std;

class ComboMedia : public Media {
public:
    ComboMedia(string name);
    ComboMedia(vector<Media*> m, string name);
    double area() const;
    double perimeter() const;
    void accept(MediaVisitor * cmVisitor);
    void add(Media *m);
    void removeMedia(Media *m);

private:
    vector<Media*> media;
    string mediaName;
};

#endif
