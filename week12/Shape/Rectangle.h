#pragma once
#include "Shape.h"

class Rectangle: public Shape{
public:
   Rectangle():Shape(2){
   }
     int findArea() const override {  }
     bool isPointIn(int x, int y) const override{}

     Shape* clone() const override {
       return new Rectangle();
   }

     void whoAmI() const { std::cout<<"Rectangle";}

};


