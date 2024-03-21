#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#pragma warning (disable:4996);

using std::cout;
using std::endl;
using std::cin;

constexpr int maxFieldRows = 10;
constexpr int maxFileSize =75000;
constexpr int maxRowSize = 750;

typedef char FIELD[50];

class Row{
    FIELD row[10];
    int countCols = 0;

public:

    //look for a better way to initiallize empty char[]
    Row(){
        //strcat(row[countCols] ,"");
        row[countCols][0] = '\0';
    }

    void addField(const char* field)
    {
        strcpy(row[countCols],field);
        countCols++;
    }

    //testing
    void addEmpty()
    {
        countCols++;
    }

    void addSpecialField(const char* field)
    {
        strcpy(row[countCols],"*");
        strcat(row[countCols],field);
        strcat(row[countCols],"*");
        countCols++;
    }

    void printRow() const{
        //cout<<"|";
        for(int i = 0; i < countCols; i++)
            cout<<row[i]<<" | ";
    }

    int getCountCol() const{
        return countCols;
    }

    int getFieldSizeAtCol(int col) const
    {
        return strlen(row[col]);
    }

    void printField(int col)const{
        cout<<row[col];
    }

    const FIELD& getFieldAtCol(int col) const {
        return row[col];
    }


};

class Table{
    Row rows[10];
    size_t countRows = -1;

    int maxSpacesForEachColl[10]{0};
    int maxCountColl = 0;

    void findMaxCountColl()
    {
        for(int i = 0; i < 10; i++)
        {
            if(rows[i].getCountCol() > maxCountColl)
                maxCountColl = rows[i].getCountCol();
        }
    }
    void findMaxSpacesForEachColl()
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

public:

    Table(){}

    void read()
    {
        findMaxCountColl();
        findMaxSpacesForEachColl();
    }

    void addRow()
    {
        countRows++;
    }

    void addSpecialField(const char* str)
    {
      rows[countRows].addSpecialField(str);
    }

    void addField(const char* str)
    {
        rows[countRows].addField(str);
    }

    //????? zashto + 1 za printa bachka
    void print() const{
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

    void implementTag(char tag, const char* str)
    {
        switch (tag){
            case 'r' :addRow(); break;
            case 'h' : addSpecialField(str); break;
            case 'd' : addField(str); break;
        }
    }

    //tester
    void printSpacesCol()
    {
        for(int i = 0; i < maxCountColl; i++)
        {
            cout<<"col:"<<i<<" maxSpaces:"<<maxSpacesForEachColl[i] <<"\n";
        }
    }

};

void getFileAsString(const char* fileName, char* wholeFile)
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
void removeSpaces(char* wholeFile)
{
    std::stringstream ss(wholeFile);
    char result [1024] = "";

    while(!ss.eof())
    {
        char line[100];
        ss.getline(line, 100, ' ');

        if(strcmp(line, "") == 0)
            continue;

        strcat(result, line);

        //needs check
        ss.clear();
    }
    strcpy(wholeFile,result);
}
Table readTableFromFile(const char* fileName)
{
    Table table;

    char wholeFile[maxFileSize] = "";
    getFileAsString(fileName, wholeFile);
    removeSpaces(wholeFile);

    std::stringstream sstream(wholeFile);
    while(!sstream.eof())
    {
        char word[100];
        sstream.getline(word, 100, '<');

        table.implementTag(word[1],word + 2);
    }

    return table;
};

int main() {

    Table table = readTableFromFile("file.txt");
    table.read();
    table.print();

}