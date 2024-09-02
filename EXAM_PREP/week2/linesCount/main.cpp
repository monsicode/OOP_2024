#include <iostream>
#include <fstream>
using namespace std;

int countLines(ifstream& file){
    int count = 0;
    while(!file.eof())
    {
        char cur = file.get();
        if('\n' == cur)
        {
            count ++;
        }
    }

    //защото последния ред не завършва с \n
    return count + 1;
}


int main() {
    ifstream file("file.txt");

    cout<<countLines(file);
    //if...

    file.close();
}
