#pragma once
#include "Shape.h"

class Circle : public Shape {
   double radius;

public:
      Circle(): Shape(1){}

    bool intersect(const Shape* other) const override;

    bool intersectWithCircle(const Circle* other) const override;
    bool intersectWithRectangle(const Rectangle* other) const override;

};

