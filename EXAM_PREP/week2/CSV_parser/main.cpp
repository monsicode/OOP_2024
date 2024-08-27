#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

constexpr int MAX_FIELDS = 10;
constexpr int SIZE_FIELD = 100;
constexpr int MAX_ROWS = 5;


struct Field{
    char str[SIZE_FIELD];

    const char* getField() const{
        return str;
    }

    void setField(const char* str){
        std::strcpy(this->str, str);
    }

    void print()const
    {
        cout<<str<<" ";
    }

};

struct Row{
    Field fields[MAX_FIELDS];
    unsigned countFields = 0;

    void setField(const char* field){
        fields[countFields].setField(field);
        countFields++;
    }

    void print() const{
        for(int i = 0; i < countFields; i++)
        {
            fields[i].print();
        }
    }

};

struct CsvTable{
    Row rows[MAX_ROWS];
    unsigned countRows = 0;

    void setRow(const Row& row)
    {
        rows[countRows++] = row;
    }

    void print() const{
        for(int i = 0; i < countRows; i++)
        {
            rows[i].print();
            cout<<endl;
        }
    }

};

void parseRow(const char* row, Row& rowToParse)
{
  std::stringstream ss(row);

  while(!ss.eof())
  {
      char curField[SIZE_FIELD];
      ss.getline(curField, SIZE_FIELD, ';');
      rowToParse.setField(curField);
  }
}

void parseTable(const char* fileName, CsvTable& table)
{
    ifstream ifs(fileName);

    if(!ifs.is_open())
    {
        cout<<"Error openning!";
        return;
    }

    while(! ifs.eof())
    {
        char curRow [MAX_FIELDS * SIZE_FIELD];
        ifs.getline(curRow, MAX_FIELDS * SIZE_FIELD, '\n');

        Row row;
        parseRow(curRow, row);

        table.setRow(row);
    }
    ifs.close();
}





void modify(const char* fileName,CsvTable& table)
{
    fstream fstr(fileName);

    if(!fstr.is_open())
    {
        cout<<"Error openning!";
        return;
    }

    while(!fstr.eof())
    {

    }
}

int main() {

    CsvTable table;

    parseTable("file.txt", table);
    table.print();



//    ofstream ofs("file.txt");


//    Row r;
//    parseRow("ababbaa; dasdasdasd; uuh5gs;",r);
//
//    r.print();

//    stringstream ss("abcdBHJG;i;g");
//
//    while(!ss.eof())
//    {
//        char word[100];
//        ss.getline(word, 100, ';');
//        cout<<word<<'\n';
//    }

}
