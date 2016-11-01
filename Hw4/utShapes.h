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

#include<iostream>

using namespace std;

const double epsilon = 0.000001;

TEST(first, ShapeMediaBuilder){
    Circle c1(0, 0, 5);

    ShapeMediaBuilder smb;
    smb.buildShapeMedia(&c1);

    Media *smCircle = smb.getMedia();

    DOUBLES_EQUAL(78.5, smCircle->area(), epsilon);
}

TEST(second, buildHouse){
    Triangle t1(0, 20, 16, 32, 25 ,20);
    Rectangle r1(0, 0, 25, 20);
    Circle c1(12, 5, 2);
    Rectangle r2(10, 0, 15, 5);

    ComboMediaBuilder cmb1, cmb2, cmb3;
    cmb1.buildComboMedia();
    cmb1.buildShapeMedia(&r2);
    cmb1.buildShapeMedia(&c1);
    Media *combo1 = cmb1.getMedia();

    cmb2.buildComboMedia();
    cmb2.buildShapeMedia(combo1);
    cmb2.buildShapeMedia(&r1);
    Media *combo2 = cmb2.getMedia();

    cmb3.buildComboMedia();
    cmb3.buildShapeMedia(combo2);
    cmb3.buildShapeMedia(&t1);
    Media *combo3 = cmb3.getMedia();

    descriptionVisitor dv;

    combo3->accept(&dv);

    CHECK("combo(combo(combo(r(10 0 15 5)c(12 5 2))r(0 0 25 20))t(0 20 16 32 25 20))" == dv.getDescription());
}

TEST(third, TextMedia){
    Rectangle rec(10, 0, 15, 5);
    Text t1(rec, "I am a text media !");
    TextMedia tm(&t1);

    CHECK("I am a text media !" == tm.getText());
}

TEST(fourth, removeShapeMedia){
    Triangle t1(0, 20, 16, 32, 25 ,20);
    Rectangle r1(0, 0, 25, 20);
    Circle c1(12, 5, 2);
    Rectangle r2(10, 0, 15, 5);

    ComboMediaBuilder cmb1, cmb2, cmb3;

    cmb1.buildComboMedia();
    cmb1.buildShapeMedia(&r2);
    cmb1.buildShapeMedia(&c1);
    Media *combo1 = cmb1.getMedia();

    cmb2.buildComboMedia();
    cmb2.buildShapeMedia(combo1);
    cmb2.buildShapeMedia(&r1);
    Media *combo2 = cmb2.getMedia();

    cmb3.buildComboMedia();
    cmb3.buildShapeMedia(combo2);
    cmb3.buildShapeMedia(&t1);
    Media *combo3 = cmb3.getMedia();

    ShapeMedia *removeComponent = cmb2.findMedia(&r1);
    combo2->removeMedia(removeComponent);

    descriptionVisitor dv;

    combo3->accept(&dv);

    CHECK("combo(combo(combo(r(10 0 15 5)c(12 5 2)))t(0 20 16 32 25 20))" == dv.getDescription());
}

#endif
