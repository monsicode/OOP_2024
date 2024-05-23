#pragma once
#include <math.h>
#include "Shape.h"

class Circle: public Shape{
   double radius;
public:

    Circle(double r, int x, int y) : Shape(1)
    {
        setPoint(0,x,y);
        radius = r;
    }

    int findArea() const override{
        return 3.14*pow(radius,2);
    }

    Shape* clone() const override{
        return new Circle(*this);
    }

     bool isPointIn(int x, int y) const override{
       Shape::Point p(x,y);
       return p.findDist(getPointAtIndex(0)) <=radius;
    }

     void whoAmI() const override{
        std::cout<<"Circle with r:"<<radius;
    }

};

