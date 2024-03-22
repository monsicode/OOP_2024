#include "Table.h"

void Table::findMaxCountColl()
{
    for(int i = 0; i < 10; i++)
    {
        if(rows[i].getCountCol() > maxCountColl)
            maxCountColl = rows[i].getCountCol();
    }
}
void Table::findMaxSpacesForEachColl()
{
    for(int i = 0; i < 10; i++)//for the coll
    {
        for(int j = 0; j < maxCountColl; j++) // for the rows
        {
            if( maxSpacesForEachColl[i] < rows[j].getFieldSizeAtCol(i))
                maxSpacesForEachColl[i] = rows[j].getFieldSizeAtCol(i);
        }
    }
}


Table::Table(){}

//remove later
void Table::read()
{
    findMaxCountColl();
    findMaxSpacesForEachColl();
}


void Table::addRow()
{
    countRows++;
}

void Table::addSpecialField(const char* str)
{
    rows[countRows].addSpecialField(str);
}

void Table::addField(const char* str)
{
    rows[countRows].addField(str);
}

//????? zashto + 1 za printa bachka
void Table::print() const{
    for (int i = 0; i < countRows + 1; i++)// rows
    {
        for (int j = 0; j < maxCountColl; j++)//coll
        {
            if(strcmp(rows[i].getFieldAtCol(j),"") != 0){
                rows[i].printField(j);
            }// print field

            int neededSpaces = maxSpacesForEachColl[j] - rows[i].getFieldSizeAtCol(j);

            for(int s = 0; s < neededSpaces; s++) {
                cout << " ";
            }

            cout<<"|";
        }
        cout << std::endl;
    }
}

void Table::implementTag(char tag, const char* str)
{
    switch (tag){
        case 'r' :addRow(); break;
        case 'h' : addSpecialField(str); break;
        case 'd' : addField(str); break;
    }
}

//tester
void Table::printSpacesCol()
{
    for(int i = 0; i < maxCountColl; i++)
    {
        cout<<"col:"<<i<<" maxSpaces:"<<maxSpacesForEachColl[i] <<"\n";
    }
}
