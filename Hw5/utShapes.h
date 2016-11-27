#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include<math.h>
#include<vector>
#include "..\cppunitlite\TestHarness.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "MediaBuilder.h"
#include "Document.h"

#include<iostream>

using namespace std;

const double epsilon = 0.000001;

TEST(first, openFile){
    MyDocument document;

    CHECK(document.openDocument("myShape.txt") == "combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))");
}

TEST(second, builder_director){
}

#endif
