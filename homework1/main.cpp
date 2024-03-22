#include "Row.h"
#include "Table.h"

#pragma warning (disable:4996);

using std::cout;
using std::endl;
using std::cin;


int main() {

     Table table ("file.txt");
     table.print();
     table.add(5);
    table.print();

     table.saveTable("newTable2.txt");


}