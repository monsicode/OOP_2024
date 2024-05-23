#pragma once
#include <iostream>
#include "Shape.h"

class ShapeCollection {
    Shape** shapes = nullptr;
    size_t capacity = 4;
    size_t  countShapes = 0;

    void free();
    void copyFrom(const ShapeCollection& other);
    void moveFrom(ShapeCollection&& other);
    void resize();

public:
    ShapeCollection();
    ShapeCollection(const ShapeCollection& other);
    ShapeCollection(ShapeCollection&& other) noexcept;
    ShapeCollection& operator=(const ShapeCollection& other);
    ShapeCollection& operator=(ShapeCollection&& other) noexcept;
    ~ShapeCollection() noexcept;


    void addFigure(const Shape& figure);
    void addFigure( Shape* figure);

    int getAreaByIndex(unsigned index) const;
    int getPerByIndex(unsigned index) const;
    bool getIsPointIn(unsigned index,unsigned x, unsigned y) const;

    const Shape* operator[](unsigned index) const;
    Shape* operator[](unsigned index);

    unsigned getCountShapes() const;

    void printFigure() const;


};

