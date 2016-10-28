#ifndef SHAPELIB_H_INCLUDED
#define SHAPELIB_H_INCLUDED

#include<vector>
#include "Shape.h"

using namespace std;

double sumOfArea(const vector<Shape *> &shapes);
double sumOfPerimeter(const vector<Shape *> &shapes);
int compareMethod (const void * a, const void * b);
Shape *maxAreaShape(vector<Shape *> &shapes);
vector<Shape *> sortByDecreasingPerimeter(vector<Shape *> &shapes);

#endif
