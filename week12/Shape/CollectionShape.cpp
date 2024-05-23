#include "CollectionShape.h"

void ShapeCollection::free() {
    for(int i = 0; i < countShapes; i++)
        delete shapes[i];
    delete shapes;
}

void ShapeCollection::copyFrom(const ShapeCollection &other) {
    capacity = other.capacity;
    countShapes = other.countShapes;

    shapes = new Shape*[capacity];
    for(int i = 0; i < countShapes; i++)
    {
      shapes[i] = other.shapes[i]->clone(); //!!! clone
    }
}

void ShapeCollection::moveFrom(ShapeCollection &&other) {
    capacity = other.capacity;
    countShapes = other.countShapes;
    shapes = other.shapes;

    other.shapes = nullptr; //!!! prenasochvane na ptr
    other.countShapes = 0;
    other.capacity = 0;
}

void ShapeCollection::resize() {
        capacity *= 2;
        Shape **newShapes = new Shape *[capacity];

        for (int i = 0; i < countShapes; i++) {
            newShapes[i] = shapes[i]; //!!! не правим клониране   -- копираме указателите, не обектите към които сочат
        }

        delete[] shapes;
        shapes = newShapes;
}

ShapeCollection::ShapeCollection() {
    shapes = new Shape* [capacity];
}

ShapeCollection::ShapeCollection(const ShapeCollection &other) {
    copyFrom(other);
}

ShapeCollection::ShapeCollection(ShapeCollection &&other) noexcept {
    moveFrom(std::move(other));
}

ShapeCollection &ShapeCollection::operator=(const ShapeCollection &other) {
     if(this != &other)
     {
         free();
         copyFrom(other);
     }
     return *this;
}

ShapeCollection &ShapeCollection::operator=(ShapeCollection &&other) noexcept {

    if(this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ShapeCollection::~ShapeCollection() noexcept {
  free();
}

void ShapeCollection::addFigure(const Shape& figure) {
    if(countShapes == capacity)
        resize();

    shapes[countShapes++] = figure.clone();

}

//!!! attetion how we add
void ShapeCollection::addFigure(Shape* figure) {
    if(countShapes == capacity)
        resize();

    shapes[countShapes++] = figure;
    figure = nullptr;
}

int ShapeCollection::getAreaByIndex(unsigned int index) const {
    return shapes[index]->findArea();
}

int ShapeCollection::getPerByIndex(unsigned int index) const {
    return shapes[index]->findPerimeter();
}

bool ShapeCollection::getIsPointIn(unsigned int index, unsigned x, unsigned y) const {
   return shapes[index]->isPointIn(x,y);
}

const Shape *ShapeCollection::operator[](unsigned int index) const {
    return shapes[index];
}

Shape *ShapeCollection::operator[](unsigned int index) {
    return shapes[index];
}

unsigned ShapeCollection::getCountShapes() const {
   return countShapes;
}

void ShapeCollection::printFigure() const{
    for(int i = 0; i < countShapes; i++)
    {
        std::cout<<"index:" << i<<" ";
        shapes[i]->whoAmI();
        std::cout<<std::endl;
    }
}
