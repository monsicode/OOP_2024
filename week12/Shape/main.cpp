#pragma once
#include "CollectionShape.h"
#include "ShapeFactory.h"


using namespace std;

int main() {
 try {

     ShapeCollection collection;

     cout<<"Enter num of figures: ";
     int n;
     cin>>n;

     for(int i = 0; i < n; i++)
     {
         collection.addFigure(factory());
     }

     cout<<collection.getCountShapes();
     collection.printFigure();

 }

 catch(std::out_of_range)
 {
     cout<<"Out of range";
 }
 catch(...)
 {
     cout<<"Error found";
 }

}
