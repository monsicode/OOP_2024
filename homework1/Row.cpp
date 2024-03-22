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

void Row::saveRow(std::ofstream& ofs)
{
    ofs <<"  "<< "<tr>" << endl;
    for(int i = 0; i < countCols ; i++)
    {
        if(row[i][0] == '*')
        {
            size_t length = strlen(row[i]) - 1;
            char substring[length - 1];
            strncpy(substring, row[i] + 1, length - 1);
            substring[length - 1] = '\0';

            ofs <<"    "<< "<th>" <<substring <<"</th>"<< endl;
        }

        else
        {
            ofs <<"    "<< "<td>" << row[i] <<"</td>"<< endl;
        }
    }
    ofs <<"  "<< "</tr>" << endl;
}

