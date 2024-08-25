#include <iostream>
using namespace std;

bool isLittleEndian(){

    union test{
        unsigned char arr[4];
        uint32_t n = 1;
    }myTest;

    return myTest.arr[0];
}

union print{
    uint32_t n;
    unsigned char arr[4];
    short sh;
};

int main() {
    print obj;

    obj.n = 12388; // normal decimal
    // 64 30 00 00 in hex little endian
    // d   0 .. .. in ascii
    cout<<hex<<obj.n;



}
