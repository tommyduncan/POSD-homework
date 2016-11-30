#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include<iostream>
#include<math.h>
#include<vector>
#include<stack>
#include<stdlib.h>
#include "..\cppunitlite\TestHarness.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "MediaBuilder.h"
#include "Document.h"
#include "MediaDirector.h"

using namespace std;

const double epsilon = 0.000001;

TEST(first, openFile){
    MyDocument document;

    CHECK(document.openDocument("myShape.txt") == "combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))");
}

TEST(second, builder_director){
    stack<MediaBuilder *> mbs;
    ComboMediaBuilder *cmb = nullptr;
    MediaDirector md;
    MyDocument document;
    unsigned int j;
    long w, x, y, z;
    char shape[16] = {'\0'}, *pEnd;

    string shapeString = document.openDocument("myShape.txt");

    for(unsigned int i = 0; i < shapeString.length(); i++){
        if(shapeString.substr(i, 5) == "combo"){
            if(cmb != nullptr){
                mbs.push(cmb);
                cmb = new ComboMediaBuilder();
                cmb->buildComboMedia();
            }else{
                cmb = new ComboMediaBuilder();
                cmb->buildComboMedia();
            }
        }else if(shapeString.substr(i, 2) == "c("){
            for(j = 0; shapeString[i] != ')'; i++, j++){
                    shape[j] = shapeString[i + 2];
            }
            shape[j] = ')';
            shape[j + 1] = '\0';

            w = strtol(shape, &pEnd, 10);
            x = strtol(pEnd, &pEnd, 10);
            y = strtol(pEnd, NULL, 10);

            cmb->buildShapeMedia(new Circle(w, x, y));

        }else if(shapeString.substr(i, 2) == "r("){
            for(j = 0; shapeString[i] != ')'; i++, j++){
                    shape[j] = shapeString[i + 2];
            }
            shape[j] = ')';
            shape[j + 1] = '\0';

            w = strtol(shape, &pEnd, 10);
            x = strtol(pEnd, &pEnd, 10);
            y = strtol(pEnd, &pEnd, 10);
            z = strtol(pEnd, NULL, 10);

            cmb->buildShapeMedia(new Rectangle(w, x, y, z));
        }
    }
    mbs.push(cmb);

    md.setMediaBuilder(&mbs);
    //cout << md.getResult() << endl;
    CHECK(md.getResult() == "combo(r(0 0 3 2)c(0 0 5)combo(r(0 0 5 4)c(0 0 10))combo(r(0 1 8 7)c(0 1 10)))");
}

#endif
