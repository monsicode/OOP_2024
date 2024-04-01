#include <iostream>
#include "DynamicSet.h"
using namespace std;

int main() {

    DynamicSet set(20);
    set.add(4);
    set.add(7);
    set.add(9);


    DynamicSet set2(40);
    set2.add(4);
    set2.add(7);
    set2.add(6);

    DynamicSet set3 = Intersect(set,set2);
    set3.print();


}
