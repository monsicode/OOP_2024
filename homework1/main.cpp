#include "Row.h"
#include "Table.h"

#pragma warning (disable:4996);

using std::cout;
using std::endl;
using std::cin;


//typedef char FIELD[50];


int main() {

    Table table ("newTable3.txt");
    table.print();

    //table.saveTable("newTable3.txt");


}