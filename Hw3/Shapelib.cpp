#include<vector>
#include<iostream>
#include<cstdlib>

#include "Shape.h"

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

int compareMethod (const void * a, const void * b)
{
    Shape *ptr_a = *(Shape **) a;
    Shape *ptr_b = *(Shape **) b;

    if (ptr_a->area() < ptr_b->area())
        return 1;
    else if (ptr_a->area() > ptr_b->area())
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
