#include <iostream>
#include "NormalCollection.h"
#include "SortedCollection.h"

enum type{
    first,
    second
};

struct A{
    A(type a){
        std::cout<<a;
    }
};

int main() {

   //A а(second);

   SortedCollection s;
   s.add(4);
   s.add(4);
   s.add(4);
   s.add(2);
   s.add(6);
   s.add(6);

   //s.print();

   //s.remove(4);

   // s.print();

    //std::cout<<s.isIn(3);

}
