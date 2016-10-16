#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include<math.h>
#include<vector>
#include<iostream>
#include "..\cppunitlite\TestHarness.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"

using namespace std;

const double epsilon = 0.000001;

TEST(first, hexagon){
    Triangle t1(0, 4, 3, 0, 3, 8);
    Triangle t2(11, 4, 8, 0, 8, 8);
    Rectangle r1(3, 8, 8, 5);

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer{&sm_t1,&sm_t2};

    ComboMedia hexagon(mediaBuffer);

    hexagon.add(&sm_r1);

    DOUBLES_EQUAL(64, hexagon.area(), epsilon);
    DOUBLES_EQUAL(62, hexagon.perimeter(), epsilon);
}

TEST(second, AreaVisitor){
    Triangle t1(0, 4, 3, 0, 3, 8);
    Triangle t2(11, 4, 8, 0, 8, 8);
    Rectangle r1(3, 8, 8, 5);

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer1{&sm_r1, &sm_t2};

    ComboMedia combo1(mediaBuffer1);

    vector<Media *> mediaBuffer2{&combo1, &sm_t1};

    ComboMedia combo2(mediaBuffer2);

    AreaVisitor mv;

    combo2.accept(&mv);

    CHECK("64 52 40 12 12 " == mv.getTrack());
}

TEST(third, perimeterVisitor){
    Triangle t1(0, 4, 3, 0, 3, 8);
    Triangle t2(11, 4, 8, 0, 8, 8);
    Rectangle r1(3, 8, 8, 5);

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer1{&sm_r1, &sm_t2};

    ComboMedia combo1(mediaBuffer1);

    vector<Media *> mediaBuffer2{&combo1, &sm_t1};

    ComboMedia combo2(mediaBuffer2);

    PerimeterVisitor pv;

    combo2.accept(&pv);

    CHECK("62 44 26 18 18 " == pv.getTrack());
}

#endif
