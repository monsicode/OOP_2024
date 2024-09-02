#include <iostream>
#include <fstream>

using namespace std;

//why it doesn't replace the first found:
void replace(const char* fileName, char ch1, char ch2)
{
    fstream file(fileName, ios::in | ios::out);

    //if open...

    while(!file.eof())
    {
        char cur = file.get();

        if(ch1 == cur)
        {
            file.seekp(-1,ios::cur);
            file.put(ch2);
            file.flush();
        }
    }

    file.close();
}



int main() {

    replace("file.txt", 'a', 'e');



}
