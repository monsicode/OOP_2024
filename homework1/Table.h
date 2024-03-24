#pragma once
#include <sstream>
#include "Row.h"


using namespace constants;

class Table{
    Row rows[MAX_ROWS];
    size_t countRows = -1;
    bool isThere[MAX_ROWS]{0};

    int maxSpacesForEachColl[MAX_FIELD_COUNT_IN_ROW]{0};
    int maxCountColl = 0;

    void findMaxCountColl();
    void findMaxSpacesForEachColl();
    void findMaxSpacesForCol(int col);

    void getFileAsString(const char* fileName, char* wholeFile) const;
    void removeTabulation(char* wholeFile) const;

    void implementTag(char tag, const char* str);
    void readTableFromFile(const char* fileName);
    void addRow();
    void addSpecialField(const char* str);
    void addField(const char* str);
    void chechIfCharEntity(FIELD& word) const;

public:

    Table(const char* fileName);

    void print() const;

    void remove(int rowNumber);

    void saveTable(const char* fileName) const;
    void edit(int rowNum, int colNum, const char* newVal);

    void add(int rowNumber);

};
