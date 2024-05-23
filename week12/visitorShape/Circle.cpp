#include "Circle.h"
bool Circle::intersect(const Shape* other) const {
    return other->intersectWithCircle(this);
}

bool Circle::intersectWithCircle(const Circle* other) const {
       std::cout<<"Formula for circle with circle";
       return true;
}
bool Circle::intersectWithRectangle(const Rectangle* other) const
{
   std::cout<<"Formula for circle with rectangle";
   return true;
}
