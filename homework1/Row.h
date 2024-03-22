#pragma once
#pragma warning (disable:4996);
#include <iostream>
#include <cstring>
#include <fstream>
#include "Constants.h"

using namespace constants;

using std::cout;
using std::endl;
using std::cin;
typedef char FIELD[50];


class Row{
    FIELD row[10];
    int countCols = 0;

public:
    Row();

    void addField(const char* field);

    //testing
    void addEmpty();

    void addSpecialField(const char* field);

    void printRow() const;

    int getCountCol() const;

    int getFieldSizeAtCol(int col) const;

    void printField(int col)const;

    const FIELD& getFieldAtCol(int col) const ;

    void saveRow(std::ofstream& ofs);

    void deleteRow();

    void setFieldAtCol(int numCol, const char* val);

};