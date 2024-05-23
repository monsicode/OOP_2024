//#include "Shape.h"
#include "Shape.h"
#include <assert.h>

     int Shape::findPerimeter() const{

        assert(countPoints >=3 );

        int sum = 0;

        for(int i = 0; i < countPoints - 1; i++)
        {
            sum += point[i].findDist(point[i+1]);
        }

        return sum + point[countPoints - 1].findDist(point[0]);
    }

    const Shape::Point& Shape::getPointAtIndex(int index) const
    {
        //!!! proverka
        if(index >= countPoints)
            throw std::out_of_range("Invalid index");

        return point[countPoints - 1];
    }


    void Shape::setPoint(int ind, int x, int y){
        // with for() ?
        if(ind >= countPoints)
            throw std::out_of_range("Invalid point index!");

        point[ind] = Point(x,y);
    }


Shape::Shape(size_t countPoints)
    {
        this->countPoints = countPoints;
        point = new Point[countPoints];
    }
Shape::Shape(const Shape& other)
    {
        copyFrom(other);
    }
Shape::Shape(Shape&& other) noexcept{
        moveFrom(std::move(other));
    }
    Shape& Shape::operator=(const Shape& other)
    {
        if(this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    Shape& Shape::operator=(Shape&& other){
        if(this != &other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }
     Shape::~Shape(){
        free();
    }

    void Shape::free(){
        delete[] point;
    }

    void Shape::copyFrom(const Shape& other){
        countPoints = other.countPoints;
        point = new Point[countPoints];

        for(int i = 0; i < countPoints; i++)
            point[i] = other.point[i];
    }

    void Shape::moveFrom(Shape&& other)
    {
        countPoints = other.countPoints;
        point = other.point;

        other.point = nullptr;
    }








//Shape::Shape(size_t pointsCount) : pointsCount(pointsCount)
//{
//    point = new Point[pointsCount]; // [0,0], [0,0]....
//}
//
//void Shape::copyFrom(const Shape& other)
//{
//    point = new Point[other.countPoints];
//
//    for (int i = 0; i < other.countPoints; i++)
//        point[i] = other.point[i];
//
//    countPoints = other.countPoints;
//}
//void Shape::moveFrom(Shape&& other)
//{
//    point = other.point;
//    other.point = nullptr;
//
//    countPoints = other.countPoints;
//}
//void Shape::free()
//{
//    delete[] point;
//}
//
//Shape::Shape(const Shape& other)
//{
//    copyFrom(other);
//}
//Shape::Shape(Shape&& other) noexcept
//{
//    moveFrom(std::move(other));
//}
//
//Shape& Shape::operator= (const Shape& other)
//{
//    if (this != &other)
//    {
//        free();
//        copyFrom(other);
//    }
//    return *this;
//}
//Shape& Shape::operator=(Shape&& other) noexcept
//{
//    if (this != &other)
//    {
//        free();
//        moveFrom(std::move(other));
//    }
//    return *this;
//}
//
//Shape::~Shape()
//{
//    free();
//}
//
//const Shape::Point& Shape::getPointAtIndex(size_t index) const
//{
//    if (index >= pointsCount)
//        throw std::exception("Invalid point index!");
//
//    return  points[index];
//}
//
//void Shape::setPoint(size_t pointIndex, int x, int y)
//{
//    if (pointIndex >= pointsCount)
//        throw std::exception("Invalid point index!");
//
//    points[pointIndex] = point(x, y);
//}
//
//double Shape::getPer() const //we sum the distance of all consecutive points
//{
//    assert(pointsCount >= 3);
//
//    double per = 0;
//    for (int i = 0; i < pointsCount - 1; i++)
//        per += points[i].getDist(points[i + 1]);
//    return per + points[pointsCount - 1].getDist(points[0]);
//}