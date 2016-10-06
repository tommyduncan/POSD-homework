#ifndef TRIANGLES_H_INCLUDED
#define TRIANGLES_H_INCLUDED

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

#endif // TRIANGLES_H_INCLUDED
