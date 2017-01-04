#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <vector>
#include <string>
#include <sstream>

#define PI 3.14

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string description() const {return std::string("");}
    virtual std::string getName() const = 0;
    virtual void setName(std::string name);
};

double sumOfArea(const std::vector<Shape *> & shapes);

class Rectangle : public Shape
{
public:
    Rectangle(double ulcx, double ulcy, double length, double width):
        x(ulcx),y(ulcy),l(length),w(width) {}
    double area() const
    {
        return l*w;
    }

    double perimeter() const {
        return 2*(l+w) ;
    }
    std::string description() const {
        std::stringstream ss;
        ss << "r(" << x << " " << y << " " << l << " " << w << ") ";
        return ss.str();
    }
    std::string getName()const {
        return name;
    }
    void setName(std::string name){
        this->name=name;
    }
private:
    double x,y,l,w;
    std::string name;
};

class Circle : public Shape
{
public:
    Circle(double centerX,double centerY,double radius):
        cx(centerX),cy(centerY),r(radius) {}
    double area()const
    {
        return 3*r*r;
    }

    double perimeter() const {
        return 2*PI*r ;
    }
    std::string description() const {
        std::stringstream ss;
        ss << "c(" << cx << " " << cy << " " << r << ") ";
        return ss.str();
    }
    std::string getName()const {
        return name;
    }
    void setName(std::string name){
        this->name=name;
    }
private:
    double cx,cy,r;
    std::string name;
};


double sumOfArea(const std::vector<Shape *> & shapes)
{
    double total =0;
    for (Shape *s: shapes)
        total += s->area();
    return total;
}

#endif // SHAPES_H_INCLUDED
