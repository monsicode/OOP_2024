#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#pragma warning (disable:4996);

using std::cout;
using std::endl;
using std::cin;

//int maxCountColl = 0;

bool flagTableTag = false;

constexpr int maxFieldRows = 10;

typedef char FIELD[50];

class Row{
    FIELD row[10] ;
    int countCols = 0;

public:
    Row(){
        strcat(row[countCols] ,"");
    }

    void addField(const char* field)
    {
        strcpy(row[countCols],field);
        countCols++;

//        if(maxCountColl < countCols)
//            maxCountColl = countCols;
    }

    void printRow() const{
        for(int i = 0; i < countCols; i++)
                 cout<<row[i]<<" | ";
    }

    int getCountCol() const{
        return countCols;
    }

    int getFieldSizeAtCol(int col)
    {
        return strlen(row[col]);
    }



};

class Table{
    Row rows[10];
    size_t countRows = -1;
    int maxSizeForCol[10];

public:
    void addRow()
    {
       countRows++;
    }

//    int getMaxSizeForCol()
//    {
//       for(int i = 0; i < countRows; i++)
//       {
//           for(int j = 0; j <  maxCountColl; j++) {
//               rows[i].getFieldSizeAtCol(1);
//           }
//       }
//
//    }

//    int findCountColls() const
//    {
//        for(int i = 0; i < countRows; i++) {
//
//        }
//    };

    void addFieldToRow(const char* str)
    {
        rows[countRows].addField(str);
    }

    //????? zashto + 1 za printa bachka
    void print() const{
        for (int i = 0; i < countRows + 1; i++)
        {
            rows[i].printRow();
            cout << std::endl;
        }
    }

    size_t getCountRows() const{
        return countRows;
    }
};


//good for now
bool isOnlyTag(const char* tag)
{
    if(strcmp(tag,"<table>") == 0 || strcmp(tag,"</table>") == 0 || strcmp(tag,"<tr>") == 0 || strcmp(tag,"</tr>") == 0 ||
       strcmp(tag,"<td>") == 0 || strcmp(tag,"</td>") == 0 || strcmp(tag,"<th>") == 0 || strcmp(tag,"</th>") == 0)
        return true;

    return false;
}
bool isOnlyString(const char* str)
{
    int sizeStr = strlen(str);
    if(str[0] != '<' && str[sizeStr - 1] != '>')
        return true;
    return false;
}


int  countOpeningTags(const char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '<' )
            count++;
    }
    return count;
}
int  countClosingTags(const char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '/' )
            count++;
    }
    return count;
}

//other tag functons
int checkTag(const char* tag)
{
    if(strcmp(tag,"<tr") == 0 || strcmp(tag,"</tr") == 0)
       return 1;
    else if(strcmp(tag,"<th") == 0 || strcmp(tag,"</th") == 0)
        return 2;
    else if(strcmp(tag,"<td") == 0 || strcmp(tag,"</td") == 0)
        return 3;
}

//chlen func to table
void implementTag(int tag, const char* str, Table& table)
{
    switch (tag){
        case 1 : table.addRow(); return;
        case 2 : table.addFieldToRow(str); return;
        case 3 : table.addFieldToRow(str); return;
    }
    return;
}

//reading a line
void readLineHelper(char* line)
{
    std::stringstream ss(line);

    while (!ss.eof()) {
        ss.get(line, 20, '>');

        if(strcmp(line,"<tr") == 0 || strcmp(line,"</th"))
            cout<<"newLIne ";
        else if(strcmp(line,"<th") == 0 || strcmp(line,"</th"))
            cout<<'*';

        ss.get(line, 20, '<');

        //table.addRow(line);
        cout << line << "\n";
    }
}

void readLine(std::ifstream& ifs)
{
    char line[100];
    ifs.getline(line, 100);

//    isOnlyTag(line);
//    isOnlyString(line);

   int countTags = countOpeningTags(line);
   int closingTags = countClosingTags(line);

   //if many tags are on the same line
   if(countTags - closingTags > 1)
   {
       if(!flagTableTag)
       {
           char newLine[100];
           flagTableTag = true;
           strcpy(newLine, line + 7);
           cout<<newLine;

           readLineHelper(newLine);
       }

       else
       {
           readLineHelper(line);
       }
   }

   readLineHelper(line);
}

void readFile(const char* fileName)
{

}


int main() {
//
//    Table table;
 //  readFile("file.txt");
//    table.print();

    std::ifstream ifs("file.txt");

    char wholeFile[1024] = "";

    char buff[1024];
    while(ifs.getline(buff, 1024))
    {
        std::stringstream ss(buff);

        char line[100];
        while(!ss.eof())
        {
            ss.getline(line, 100, '>');
//            if(strcmp(line, "<th") == 0 || strcmp(line, "<td") == 0)
//                cout<<"special treatment";
            strcat(wholeFile,line);
        }
    }


    std::stringstream ss(wholeFile);

    char result [1024] = "";
   // cout<<wholeFile;
    while(!ss.eof())
        {
            char line[100];
            ss.getline(line, 100, ' ');

            if(strcmp(line, "") == 0)
                continue;

           strcat(result, line);

           ss.clear();
    }

    std::stringstream sstream(result);
    while(!sstream.eof())
    {
        char word[100];
        sstream.getline(word, 100, '<');


        if(word[1] == 'h')
        {
            cout<<'*'<<word + 2 <<'*'<<" | ";
        }
        else if(word[1] == 'd')
        {
            cout<<word + 2 <<" | ";
        }
        else if(word[1] == 'r')
        {
            cout<<endl;
        }
       //else cout<<word<<"\n";


    }
}
