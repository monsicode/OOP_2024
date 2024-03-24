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

typedef char FIELD[MAX_FIELD_SIZE];

class Row{
    FIELD row[MAX_FIELD_COUNT_IN_ROW];
    int countCols = 0;

public:
    Row();

    void addField(const char* field);

    void addSpecialField(const char* field);

    size_t getCountCol() const;

    size_t getFieldSizeAtCol(size_t col) const;

    void printField(size_t col)const;

    void saveRow(std::ofstream& ofs) const;

    void deleteRow();

    void setFieldAtCol(size_t numCol, const char* val);

};