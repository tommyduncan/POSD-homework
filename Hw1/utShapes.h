#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Shapes.h"
#include <vector>

using namespace std;

const double epsilon = 0.000001;

/* ======================== HW1 ======================== */

TEST (first, Rectangle) {
    Rectangle rect(0, 0, 4, 2);
    DOUBLES_EQUAL(8, rect.area(), epsilon);
}

TEST(sencond,Circle)
{
    Circle circ(0, 0, 10);
    DOUBLES_EQUAL(314, circ.area(), epsilon);
}

TEST (third, Triangle){
    Triangle tri(0, 2, -3, 0, 0, 0);
    DOUBLES_EQUAL(3, tri.area(), epsilon);
}

TEST (fourth, Rectangle){
    Rectangle rect(0, 0, 4, 2);
    DOUBLES_EQUAL(12, rect.perimeter(), epsilon);
}

TEST (fifth, Circle){
    Circle circ(0, 0, 10);
    DOUBLES_EQUAL(62.8, circ.perimeter(), epsilon);
}

TEST (fifth, Triangle){
    Triangle tri(0, 0, 3, 0, 0, 4);
    DOUBLES_EQUAL(12, tri.perimeter(), epsilon);
}

TEST (sixth, sumOfArea) {
    Rectangle r1(0, 0, 4, 2);
    Circle c1(0, 0, 10);
    Triangle t1(0, 2, -3, 0, 0, 0);

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    DOUBLES_EQUAL(325, sumOfArea(ss), epsilon);
}

TEST (sixth, sumOfPerimeter) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1(0, 0, 3, 0, 0, 4);

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    DOUBLES_EQUAL(86.8, sumOfPerimeter(ss), epsilon);
}

/* ======================== HW2 ======================== */

TEST (seventh, maxArea){
    Rectangle r1(0, 0, 4, 2);
    Circle c1(0, 0, 10);
    Triangle t1(0, 2, -3, 0, 0, 0);

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    DOUBLES_EQUAL(314, maxArea(ss), epsilon);
}

TEST (eight, sortByDecreasingPerimeter) {
    Rectangle r1(0,0,4,2);
    Circle c1(0,0,10);
    Triangle t1(0, 0, 3, 0, 0, 4);

    vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);

    double *testValue = sortByDecreasingPerimeter(ss);

    DOUBLES_EQUAL(12, testValue[0], epsilon);
    DOUBLES_EQUAL(12, testValue[1], epsilon);
    DOUBLES_EQUAL(62.8, testValue[2], epsilon);
}

#endif // UTSHAPES_H_INCLUDED
