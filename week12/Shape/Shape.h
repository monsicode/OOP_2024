#pragma once
#include <math.h>
#include <iostream>
#include <assert.h>

class Shape {
public:
    struct Point{
        int x;
        int y;

        Point(){}
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        double findDist(const Point& other)
        {
            int dx = x - other.x;
            int dy = y - other.y;

            return sqrt(dx*dx -dy*dy);
        }

        void print() const{
            std::cout<<x<<" "<<y;
        }

    };

    virtual int findArea() const = 0;
    virtual int findPerimeter() const;
    virtual bool isPointIn(int x, int y) const = 0;
    virtual Shape* clone()  const = 0;
    virtual void whoAmI() const = 0;


    const Point& getPointAtIndex(int index) const;
    void setPoint(int ind, int x, int y);


    Shape(size_t countPoints);
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other);

    virtual ~Shape();


private:
    Point* point;
    int countPoints;

    void free();
    void copyFrom(const Shape& other);
    void moveFrom(Shape&& other);

};
