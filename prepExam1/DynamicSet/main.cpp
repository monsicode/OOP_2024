#include <iostream>
#include "DynamicSet.h"
using namespace std;

int main() {

    DynamicSet set(20);
    set.add(4);
    set.add(7);
    set.add(9);


    DynamicSet set2(40);
    set2.add(3);
    set2.add(34);
    set2.add(6);

    set.Union(set2);

    set.print();

}
