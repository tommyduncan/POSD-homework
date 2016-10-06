#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include "Rectangles.h"
#include "Circles.h"
#include "Triangles.h"
#include "Composite.h"
#include "Shapeslib.h"
#include <vector>

using namespace std;

const double epsilon = 0.000001;

TEST (first, maxArea){
    Rectangle r1(0, 0, 4, 2);   // Area = 8
    Circle c1(0, 0, 10);    // Area = 314
    Triangle t1(0, 2, -3, 0, 0, 0); // Area = 3

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    DOUBLES_EQUAL(314, maxAreaShape(ss)->area(), epsilon);
}

TEST (second, sortByDecreasingPerimeter) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1(0, 0, 3, 0, 0, 4);

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    double *testValue = sortByDecreasingPerimeter(ss);

    DOUBLES_EQUAL(12, *testValue, epsilon);
    DOUBLES_EQUAL(12, *(testValue + 1), epsilon);
    DOUBLES_EQUAL(62.8, *(testValue + 2), epsilon);
}

TEST (third, compositeArea) {
    Rectangle rTall(1,10,2,8);  // Area = 16
    Circle cSmall(2,1,1);   // Area = 3.14

    vector<Shape *> ss;
    ss.push_back(&rTall);

    Composite shape(ss);

    shape.addShape(&cSmall);

    DOUBLES_EQUAL(19.14, shape.area(), epsilon);
}

TEST (fourth, compositePerimeter) {
    Rectangle rTall(1,10,2,8);  // Perimeter = 20
    Circle cSmall(2,1,1);   // Perimeter = 6.28

    vector<Shape *> ss;
    ss.push_back(&rTall);

    Composite shape(ss);

    shape.addShape(&cSmall);

    DOUBLES_EQUAL(26.28, shape.perimeter(), epsilon);
}

#endif // UTSHAPES_H_INCLUDED
