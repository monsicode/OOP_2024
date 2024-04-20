#include "MultiSet.h"

using namespace std;


int main() {
   try{
       MultiSet set(10,3);
       set.add(3);
       set.add(3);
       set.add(3);
       set.add(6);
       set.add(2);
       set.add(2);
       set.add(5);

        MultiSet set4 = MultiSet::complement(set);
        set4.print();
        cout<<endl;
        set.print();
       //cout<<set.getCount(4);

       //set.serialize("first.dat");
       //set.deserialize("first.dat");

       //MultiSet set2(7,3);
       //.deserialize("first.dat");
//       set.print();
//       cout<<endl;

//   set2.add(4);
//   set2.add(3);
//   set2.add(3);
//   set2.add(6);
//    set2.print();
//    cout<<endl;
//
//    cout<<set2.getCount(8);

   //set.serialize("eho.dat");
//   MultiSet set3 =  MultiSet::deserialize("eho.dat");
//    cout<<endl;
//   set3.print();
//



   }
   catch(const std::out_of_range& err1){
       std::cout << err1.what();
   }
   catch( const std::runtime_error& err2)
   {
     std::cout<<err2.what();
     MultiSet set(10,8);
   }


}