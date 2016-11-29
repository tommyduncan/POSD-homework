#ifndef MEDIADIRECTOR_H_INCLUDED
#define MEDIADIRECTOR_H_INCLUDED

#include<stack>
#include<iostream>
#include "MediaBuilder.h"
#include "Media.h"

using namespace std;

class MediaDirector{
public:
    void setMediaBuilder(stack<MediaBuilder *> *mbs);
    void concrete(string content);

private:
    Media *media;
    stack<MediaBuilder *> *mb;
};

#endif
