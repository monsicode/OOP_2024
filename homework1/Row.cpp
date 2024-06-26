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


void Row::addSpecialField(const char* field)
{
    strcpy(row[countCols],"*");
    strcat(row[countCols],field);
    strcat(row[countCols],"*");
    countCols++;
}

size_t Row::getCountCol() const{
    return countCols;
}

size_t Row::getFieldSizeAtCol(size_t col) const
{
    return strlen(row[col]);
}

void Row::printField(size_t col)const{
    cout<<row[col];
}

void Row::setFieldAtCol(size_t numCol, const char* val)
{
    strcpy(row[numCol],val);
}

void Row::saveRow(std::ofstream& ofs) const
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

void Row::deleteRow()
{
    for(int i = 0; i < countCols; i++)
    {
        strcpy(row[i],"");
    }
}