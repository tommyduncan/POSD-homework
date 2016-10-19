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

using namespace std;

const double epsilon = 0.000001;

TEST(first, hexagon){
    Triangle t1(0, (3 * sqrt(3)), 3, 0, 3, (6 * sqrt(3)));
    Triangle t2(9, (6 * sqrt(3)), 9, 0, 12, (3 * sqrt(3)));
    Rectangle r1(3, (6 * sqrt(3)), 6, (6 * sqrt(3)));

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer{&sm_t1,&sm_t2};

    ComboMedia hexagon(mediaBuffer);

    hexagon.add(&sm_r1);

    DOUBLES_EQUAL((54 * sqrt(3)), hexagon.area(), epsilon);
    DOUBLES_EQUAL((36 + (24 * sqrt(3))), hexagon.perimeter(), epsilon);
}

TEST(second, AreaVisitor){
    Triangle t1(0, (3 * sqrt(3)), 3, 0, 3, (6 * sqrt(3)));
    Triangle t2(9, (6 * sqrt(3)), 9, 0, 12, (3 * sqrt(3)));
    Rectangle r1(3, (6 * sqrt(3)), 6, (6 * sqrt(3)));

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer1{&sm_r1, &sm_t2};

    ComboMedia combo1(mediaBuffer1);

    vector<Media *> mediaBuffer2{&combo1, &sm_t1};

    ComboMedia combo2(mediaBuffer2);

    AreaVisitor mv;

    combo2.accept(&mv);

    CHECK("93.53 77.94 62.35 15.58 15.58 " == mv.getTrack());
}

TEST(third, perimeterVisitor){
    Triangle t1(0, (3 * sqrt(3)), 3, 0, 3, (6 * sqrt(3)));
    Triangle t2(9, (6 * sqrt(3)), 9, 0, 12, (3 * sqrt(3)));
    Rectangle r1(3, (6 * sqrt(3)), 6, (6 * sqrt(3)));

    ShapeMedia sm_t1(&t1);
    ShapeMedia sm_t2(&t2);
    ShapeMedia sm_r1(&r1);

    vector<Media *> mediaBuffer1{&sm_r1, &sm_t2};

    ComboMedia combo1(mediaBuffer1);

    vector<Media *> mediaBuffer2{&combo1, &sm_t1};

    ComboMedia combo2(mediaBuffer2);

    PerimeterVisitor pv;

    combo2.accept(&pv);

    CHECK("77.56 55.17 32.78 22.39 22.39 " == pv.getTrack());
}

#endif
