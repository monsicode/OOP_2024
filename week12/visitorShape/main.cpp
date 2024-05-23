#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

bool intersect(const Shape* s1, const Shape* s2)
{
    s1->intersect(s2);
}

int main() {

    Shape* ptr = new Circle();
    Shape* ptr2 = new Rectangle();

    std::cout<<intersect(ptr2,ptr);



}
