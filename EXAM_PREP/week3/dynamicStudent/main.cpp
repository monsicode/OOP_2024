#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student{
    char* name;

    //    Student st;
//    st.name = "Ivan";
//
//    ofstream file("file.dat", ios::binary);
//
//    size_t lenStr = strlen(st.name);
//
//    file.write((const char*)&lenStr , sizeof(lenStr));
//
//    // !!! няма нужда от const char* - implicit conversion
//    file.write((const char*)st.name, lenStr);

};

size_t getFileSize(ifstream& file)
{
    int startPos = file.tellg();
    file.seekg(0, ios::end);

    int endPos = file.tellg();

    file.seekg(startPos);

    return endPos - startPos;

}

int main() {

    ifstream file("file.txt");

    cout<<getFileSize(file);

    file.close();
}
