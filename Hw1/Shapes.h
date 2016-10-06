#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width){}
    double area() const {return l * w;}
    double perimeter() const {return ((2 * l) + (2 * w));}
private:
    double x,y,l,w;
};

class Circle : public Shape{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius){}
    double area()const {return 3.14 * r * r;}
    double perimeter() const {return 2 * r * 3.14;}
private:
    double cx,cy,r;
};

class Triangle : public Shape{
    public:
        Triangle (double x1, double y1, double x2, double y2, double x3, double y3):
            a(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))),
            b(sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2))),
            c(sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2))),
            s((a + b + c) / 2){}
        double area() const{
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        double perimeter() const {return a + b + c;}
    private:
        double a, b, c, s;
};

double sumOfArea(vector<Shape *> &shapes) {
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

double sumOfPerimeter(vector<Shape *> &shapes) {
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

double maxArea(vector<Shape *> &shapes){
    double max = 0;

    for(Shape *s: shapes){
        if(s->area() > max){
            max = s->area();
        }
    }
    return max;
}

double *sortByDecreasingPerimeter(vector<Shape *> &shapes){
    double *sorted = new double[shapes.size()];
    int i = 0;

    // Fail to allocate memory.
    if(sorted == nullptr){
        printf("Out of Memory!\n");
        exit(1);
    }

    for(Shape *s: shapes){
        *(sorted + i) = s->perimeter();
        i++;
    }

    qsort(sorted, shapes.size(), sizeof(double), compare);

    return sorted;
}

#endif // SHAPES_H_INCLUDED
