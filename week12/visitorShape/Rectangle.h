#pragma once
#include "Shape.h"

class Rectangle : public Shape {

public:
    Rectangle(): Shape(2){}

    bool intersect(const Shape* other) const override;

    bool intersectWithCircle(const Circle* other) const override;
    bool intersectWithRectangle(const Rectangle* other) const override;

};

