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
static int compare (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b) return 1;
  else if (*(double*)a < *(double*)b) return -1;
  else return 0;
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

double *sortByDecreasingPerimeter(vector<Shape *> &shapes){
    double *sorted = new double[shapes.size()];
    int i = 0;

    // Fail to allocate memory.
    if(sorted == nullptr){
        cout << "Out of Memory!" << endl;
        exit(1);
    }

    for(Shape *s: shapes){
        *(sorted + i) = s->perimeter();
        i++;
    }

    qsort(sorted, shapes.size(), sizeof(double), compare);

    return sorted;
}

#endif
