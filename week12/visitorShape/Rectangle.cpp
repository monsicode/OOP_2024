#include "Rectangle.h"

bool Rectangle::intersect(const Shape* other) const {
    return other->intersectWithRectangle(this);
}

bool Rectangle::intersectWithCircle(const Circle* other) const {
    std::cout<<"Formula for rec with circle";
    return true;
}
bool Rectangle::intersectWithRectangle(const Rectangle* other) const
{
    std::cout<<"Formula for rec with rectangle";
    return true;
}