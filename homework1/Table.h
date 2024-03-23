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
    bool isThere[10]{0};

    int maxSpacesForEachColl[10]{0};
    int maxCountColl = 0;

    void findMaxCountColl();
    void findMaxSpacesForEachColl();
    void findMaxSpacesForCol(int col);

    void getFileAsString(const char* fileName, char* wholeFile);
    void removeTabulation(char* wholeFile);

    void implementTag(char tag, const char* str);
    void readTableFromFile(const char* fileName);
    void addRow();
    void addSpecialField(const char* str);
    void addField(const char* str);

public:

    Table(const char* fileName);

    void print() const;

    void remove(int rowNumber);

    void saveTable(const char* fileName);
    void edit(int rowNum, int colNum, const char* newVal);

    void add(int rowNumber)
    {
        countRows++;

        for (int i = countRows; i > rowNumber - 1; --i)
        {
//            cout<<"Enter value for column "<<i<<endl;
//            FIELD val;
//            cin>>val;
//            addField(val);
              rows[i] = rows[i - 1];
        }
        rows[rowNumber - 1].deleteRow();
        cout<<"Number in columns is: "<<maxCountColl<<endl;

        for (int j = 0; j < maxCountColl; j++) {
            FIELD val;
            cout << "Enter data for column: " << j << endl;
            cin >> val;
            rows[rowNumber - 1].setFieldAtCol(j, val);
        }

        isThere[rowNumber - 1] = true;
        isThere[countRows] = true;
    }

};
