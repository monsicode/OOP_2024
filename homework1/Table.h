#pragma once
#include <sstream>
#include "Row.h"
#include "Constants.h"
using namespace constants;




using namespace constants;

class Table{
    Row rows[MAX_ROWS];
    size_t countRows = -1;
    bool isThere[MAX_ROWS]{0};

    int maxSpacesForEachColl[MAX_FIELD_COUNT_IN_ROW]{0};
    int maxCountColl = 0;

    void findMaxCountColl();
    void findMaxSpacesForEachColl();
    void findMaxSpacesForCol(size_t col);

    void getFileAsString(const char* fileName, char* wholeFile) const;
    void removeTabulation(char* wholeFile) const;

    void implementTag(char tag, const char* str);
    void readTableFromFile(const char* fileName);
    void addRow();
    void addSpecialField(const char* str);
    void addField(const char* str);
    void chechIfCharEntity(FIELD& word) const;

//    bool validRow(size_t rowNumber) const;
//
//    bool validCol(size_t colNumber) const;
public:

    Table(const char* fileName);

    void print() const;

    void remove(size_t rowNumber);

    void saveTable(const char* fileName) const;
    void edit(size_t rowNum, size_t colNum, const char* newVal);

    void add(size_t rowNumber);

};
