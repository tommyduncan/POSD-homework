#ifndef SHAPESLIB_H_INCLUDED
#define SHAPESLIB_H_INCLUDED

#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

double sumOfArea(const vector<Shape *> &shapes) {
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

double sumOfPerimeter(const vector<Shape *> &shapes) {
    double total = 0;

    for (Shape *s: shapes)
        total += s->perimeter();
    return total;
}

/* Compare function for quick sort. */
/*static int compare (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;
}*/

static int compareMethod (const void * a, const void * b)
{
    Shape *ptr_a = *(Shape **) a;
    Shape *ptr_b = *(Shape **) b;

    if (ptr_b->area() < ptr_a->area())
        return 1;
    else if (ptr_a->area() < ptr_b->area())
        return -1;
    return 0;
}

Shape *maxAreaShape(vector<Shape *> &shapes){
    Shape *maxShape = nullptr;
    double max = 0;

    for(Shape *s: shapes){
        if(s->area() > max){
            max = s->area();
            maxShape = s;
        }
    }
    return maxShape;
}

vector<Shape *> sortByDecreasingPerimeter(vector<Shape *> &shapes){
    qsort(&shapes[0], shapes.size(), sizeof(Shape *), compareMethod);

    return shapes;
}

#endif
