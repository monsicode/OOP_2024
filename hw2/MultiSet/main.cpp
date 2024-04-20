#include "MultiSet.h"

using namespace std;


int main() {
   MultiSet set(10,3);
    set.add(3);
   set.add(3);
   set.add(6);
   set.add(2);
   set.add(2);
   set.add(5);

 set.printMem();
   //cout<<set.getCount(4);

}