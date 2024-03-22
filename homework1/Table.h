#pragma once
#pragma warning (disable:4996);
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Row.h"


class Table{
    Row rows[10];
    size_t countRows = -1;

    int maxSpacesForEachColl[10]{0};
    int maxCountColl = 0;

    void findMaxCountColl();
    void findMaxSpacesForEachColl();

    void getFileAsString(const char* fileName, char* wholeFile);
    void removeTabulation(char* wholeFile);

public:

    void readTableFromFile(const char* fileName);

    Table();

    Table(const char* fileName);

    //remove later
    void read();

    void addRow();

    void addSpecialField(const char* str);

    void addField(const char* str);

    //????? zashto + 1 za printa bachka
    void print() const;

    void implementTag(char tag, const char* str);

    //tester
    void printSpacesCol();

    void saveTable(const char* fileName);

};
