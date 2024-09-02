#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

unsigned getCountElements(ifstream& ifs)
{
    unsigned count = 0;
    int curPos = ifs.tellg();

    while(true)
    {
          if(ifs.get() == ' ')
            count++;
          if(ifs.eof())
              break;
    }

    ifs.seekg(curPos);
    return count + 1;
}

int* getArr(ifstream& ifs)
{
  unsigned sizeArr = getCountElements(ifs);
//  int* arr  = new int [sizeArr];

     int arr[sizeArr];

     for(int i = 0; i < sizeArr; i++)
     {
         ifs>>arr[i];
     }
}

int* merge(int* firstArr, unsigned sizeFirst, int* secondArr, unsigned sizeSecond)
{


}


int main() {
//    ifstream ifs(fileName);
//
//    if(!ifs.is_open())
//    {
//        cout<<"Error opennig!";
//        return nullptr;
//    }
//    ifstream ifs("file.txt");
//
//    cout<<getCountElements(ifs) + 1;
//
//    ifs.close();
}
