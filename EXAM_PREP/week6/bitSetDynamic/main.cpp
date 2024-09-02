#include "Set.h"

using namespace std;

int main() {

   Set set(17);

   Set set2(10);
   set2.add(1);
   set2.add(8);
   set2.add(7);

    set.add(7);
    set.add(2);
    set.add(4);
    set.add(15);
    set.add(11);

    Set set3 = intersect(set,set2);

    set3.printNumbers();

   //set.printBits();

}

