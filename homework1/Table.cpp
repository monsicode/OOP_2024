#include "Table.h"
#include "Constants.h"

using namespace constants;

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

Table::Table(const char* fileName)
{
    readTableFromFile(fileName);
};

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



void Table::getFileAsString(const char* fileName, char* wholeFile)
{
    std::ifstream ifs(fileName);

    if(!ifs.is_open())
    {
        return ;
    }

    char buff[maxRowSize];
    while(ifs.getline(buff,maxRowSize))
    {
        std::stringstream ss(buff);
        char line[maxRowSize];

        while(!ss.eof())
        {
            ss.getline(line, maxRowSize, '>');
            strcat(wholeFile, line);
        }
    }

    ifs.close();
}

void Table:: removeTabulation(char* wholeFile)
{
    std::stringstream ss(wholeFile);
    char result [1024] = "";

    while(!ss.eof())
    {
        char line[100];
        ss.getline(line, 100, '\t');

        if(strcmp(line, "") == 0)
            continue;

        strcat(result, line);

        //needs check
        ss.clear();
    }
    strcpy(wholeFile,result);
}


void Table::readTableFromFile(const char* fileName)
{
    char wholeFile[maxFileSize] = "";
    getFileAsString(fileName, wholeFile);
    removeTabulation(wholeFile);

    std::stringstream sstream(wholeFile);
    while(!sstream.eof())
    {
        char word[100];
        sstream.getline(word, 100, '<');

        implementTag(word[1],word + 2);
    }

   this->read();
};

void Table::saveTable(const char* fileName)
{
    std::ofstream ofs(fileName, std::ios::app);

    if(!ofs.is_open())
    {
        cout << "Error saving the table!" <<endl;
        return;
    }

    ofs<<"<table>"<<endl;

    for(int i = 0; i < countRows + 1; i++)
    {
        rows[i].saveRow(ofs);
    }

    ofs<<"</table>"<<endl;

    ofs.close();
}