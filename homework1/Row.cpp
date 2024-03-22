#include "Row.h"

Row::Row() {
    for(int i = 0; i < 10 ; i++)
    {
        strcpy(row[i] ,"");
    }
}

void Row::addField(const char* field)
{
    strcpy(row[countCols],field);
    countCols++;
}

//testing
void Row::addEmpty()
{
    countCols++;
}

void Row::addSpecialField(const char* field)
{
    strcpy(row[countCols],"*");
    strcat(row[countCols],field);
    strcat(row[countCols],"*");
    countCols++;
}

void Row::printRow() const{
    //cout<<"|";
    for(int i = 0; i < countCols; i++)
        cout<<row[i]<<" | ";
}

int Row::getCountCol() const{
    return countCols;
}

int Row::getFieldSizeAtCol(int col) const
{
    return strlen(row[col]);
}

void Row::printField(int col)const{
    cout<<row[col];
}

const FIELD& Row::getFieldAtCol(int col) const {
    return row[col];
}

