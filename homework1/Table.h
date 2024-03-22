#pragma once
#include <iostream>
#include <cstring>
#include "Row.h"
#pragma warning (disable:4996);

class Table{
    Row rows[10];
    size_t countRows = -1;

    int maxSpacesForEachColl[10]{0};
    int maxCountColl = 0;

    void findMaxCountColl();
    void findMaxSpacesForEachColl();

public:

    Table();

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
};
