#ifndef COMPOSITE_H_INCLUDED
#define COMPOSITE_H_INCLUDED

#include<vector>
#include "Shapeslib.h"

using namespace std;

class Composite : public Shape{
    public:
        Composite(const vector<Shape*> &shapes):shapes(shapes){}

        void addShape(Shape *shape){
            shapes.push_back(shape);
        }

        double area() const{
            return sumOfArea(shapes);
        }

        double perimeter() const{
            return sumOfPerimeter(shapes);
        }

    private:
        vector<Shape*> shapes;
};

#endif
