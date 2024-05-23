#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
 try {
     Shape *ptr = new Circle(4, 3, 4);
     Shape *ptr2 = new Rectangle();
     Shape* ptr3  = ptr->clone();

     ptr->getPointAtIndex(0).print();
     cout<<endl;
     ptr->whoAmI();
     cout<<endl;
     ptr2->whoAmI();


     delete ptr;
     delete ptr2;
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
