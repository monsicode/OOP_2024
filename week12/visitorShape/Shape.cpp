#include "Shape.h"


void Shape::free(){
    delete[] points;
}

void Shape::copyFrom(const Shape& other){
    points = new Point [other.countPoints];

    for(int i = 0; i < other.countPoints; i++)
    {
        points[i] = other.points[i];
    }

    countPoints = other.countPoints;
}

void Shape::moveFrom(Shape&& other) {

    points = other.points;
    countPoints = other.countPoints;

    other.points = nullptr;
    other.countPoints = 0;
}

Shape::Shape(unsigned n){
    points = new Point [n];
    countPoints = n;
}

Shape::Shape(const Shape& other){
    copyFrom(other);
}

Shape::Shape(Shape&& other){
    moveFrom(std::move(other));
}

Shape& Shape::operator=(const Shape& other){
    if(this != & other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Shape& Shape::operator=(Shape&& other){
    if(this != & other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Shape::~Shape(){
    free();
}
