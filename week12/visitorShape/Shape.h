#pragma once
#include <math.h>
#include <iostream>

class Circle;
class Rectangle;

class Shape {
    struct Point{
        int x;
        int y;

        Point() = default;
        Point(int x,int y):x(x), y(y){}

        int getDist(const Point& other) const{
            int dx = x - other.x;
            int dy = y - other.y;

            return sqrt(dx*dx + dy*dy);
        }
    };


    Point* points;
    int countPoints;

    void free();
    void copyFrom(const Shape& other);
    void moveFrom(Shape&&);

public:
    Shape(unsigned n);
    Shape(const Shape& other);
    Shape(Shape&& other);
    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other);

    //!!!
    virtual ~Shape();

    virtual bool intersect(const Shape* other) const = 0;

    virtual bool intersectWithCircle(const Circle* other) const = 0;
    virtual bool intersectWithRectangle(const Rectangle* other) const = 0;

};

