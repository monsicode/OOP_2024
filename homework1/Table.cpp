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
           findMaxSpacesForCol(i);
    }
}

void Table::findMaxSpacesForCol(int numCol)
{
    int col = numCol -1;
    for(int i = 0; i < 10; i++)
    {
        if (maxSpacesForEachColl[col] < rows[i].getFieldSizeAtCol(col))
            maxSpacesForEachColl[col] = rows[i].getFieldSizeAtCol(col);
    }
}


Table::Table(const char* fileName)
{
    readTableFromFile(fileName);
};

void Table::addRow()
{
    countRows++;
    isThere[countRows] = true;
}

void Table::addSpecialField(const char* str)
{
    rows[countRows].addSpecialField(str);
}

void Table::addField(const char* str)
{
    rows[countRows].addField(str);
}

void Table::print() const{
    for (int i = 0; i < countRows + 1; i++)// rows
    {
        if(!isThere[i])
            continue;

        for (int j = 0; j < maxCountColl; j++)//coll
        {
            rows[i].printField(j);
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
        case 'r' : addRow(); break;
        case 'h' : addSpecialField(str); break;
        case 'd' : addField(str); break;
    }
}

void Table::getFileAsString(const char* fileName, char* wholeFile) const
{
    std::ifstream ifs(fileName);

    if(!ifs.is_open())
    {
        return ;
    }

    char buff[MAX_FILE_ROW_SIZE]; // this is one line from file

    while(ifs.getline(buff, MAX_FILE_ROW_SIZE))
    {
        std::stringstream ss(buff);
        char line[MAX_FILE_ROW_SIZE];

        while(!ss.eof())
        {
            ss.getline(line, MAX_FILE_ROW_SIZE, '>');
            strcat(wholeFile, line);
        }
    }

    ifs.close();
}

void Table:: removeTabulation(char* wholeFile) const
{
    std::stringstream ss(wholeFile);
    char result [MAX_FILE_SIZE] = "";

    while(!ss.eof())
    {
        char line[MAX_FILE_ROW_SIZE];
        ss.getline(line, MAX_FILE_ROW_SIZE, '\t');

        if(strcmp(line, "") == 0)
            continue;

        strcat(result, line);
    }

    strcpy(wholeFile,result);
}

void Table::chechIfCharEntity(FIELD& word) const{
    std::stringstream ss(word);

    ss.get(word,100,'#');

    if(word[strlen(word) -1] =='&')
    {
        char hashTag;
        ss>>hashTag;
        int ch;
        ss>>ch;
        word[strlen(word) -1] =(char)ch;
    }

    FIELD  otherPart;

    ss.getline(otherPart,100);
    strcat(word,otherPart);

}

void Table::readTableFromFile(const char* fileName)
{
    char wholeFile[MAX_FILE_SIZE] = "";
    getFileAsString(fileName, wholeFile);
    removeTabulation(wholeFile);

    std::stringstream sstream(wholeFile);

    while(!sstream.eof())
    {
        FIELD word;
        sstream.getline(word, MAX_FIELD_SIZE, '<');

        chechIfCharEntity(word);

        implementTag(word[1],word + 2);
    }

    findMaxCountColl();
    findMaxSpacesForEachColl();
};

void Table::remove(int rowNumber)
{
    rows[rowNumber - 1].deleteRow();
    isThere[rowNumber - 1] = false;

    findMaxCountColl();
    findMaxSpacesForEachColl();
}

void Table::saveTable(const char* fileName) const
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
        if(isThere[i])
            rows[i].saveRow(ofs);
    }

    ofs<<"</table>"<<endl;

    ofs.close();
}

//optimisation for padding
void Table::edit(int rowNum, int colNum, const char* newVal)
{
    rows[rowNum - 1].setFieldAtCol(colNum - 1,newVal);
    findMaxSpacesForCol(colNum);
}

void Table::add(int rowNumber)
{
    countRows++;

    for (int i = countRows; i > rowNumber - 1; --i)
    {
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