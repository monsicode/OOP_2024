#include <iostream>
#include <cstring>

#include "FunctionByCriteria.hpp"

#include "MaxFunctions.h"
#include "MinFunctions.h"
#include "BinaryFileManager.h"

using namespace std;
using Function = Pair<bool, uint32_t> (*)(int);
using PolimorphicPtr = polymorphic_ptr<PartialFunction>;

void writeTest(const char *fileName) {
    ofstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    int N = 2;
    int T = 1;

    file.write((const char *) &N, sizeof(int));
    file.write((const char *) &T, sizeof(int));

    int args[2] = {3,5};
    //int res[7] = {0, 3, 3, 3, 4, 4, 0};

    file.write((const char *) args, sizeof(int) * N);
   // file.write((const char*)res, sizeof(int) * N);
}

void writeFiles(const char *fileName) {
    ofstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    int N = 3;
    file.write((const char *) &N, sizeof(int));

    int T = 3;
    file.write((const char *) &T, sizeof(int));


    const char *arr = "first.dat";
    const char *arr2 = "second.dat";
    const char *arr3 = "third.dat";

    int length1 = strlen(arr) + 1;
    int length2 = strlen(arr2) + 1;
    int length3 = strlen(arr3) + 1;

    file.write((const char *) &length1, sizeof(int));
    file.write(arr, length1);

    file.write((const char *) &length2, sizeof(int));
    file.write(arr2, length2);

    file.write((const char *) &length3, sizeof(int));
    file.write(arr3, length3);


}

void readFiles(const char *fileName) {
    ifstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    int N, T;

    file.read((char *) &N, sizeof(int));
    file.read((char *) &T, sizeof(int));

    int length1, length2;

    file.read((char *) &length1, sizeof(int));
    char *arr = new char[length1];
    file.read(arr, length1);

    file.read((char *) &length2, sizeof(int));
    char *arr2 = new char[length2];
    file.read(arr2, length2);

    cout << arr << endl;
    cout << arr2 << endl;

    delete[] arr;
    delete[] arr2;

    file.close();
}

void readTest(const char *fileName) {
    ifstream file(fileName, std::ios::binary);

    if (!file.is_open()) {
        cout << "Error";
        return;
    }

    int N, T;

    file.read((char *) &N, sizeof(int));
    file.read((char *) &T, sizeof(int));

    int args[N];
    file.read((char *) args, sizeof(int) * N);

//    int res[N];
//    file.read((char*)res, sizeof(int) * N);

    Vector<uint32_t> arg;
    //Vector<uint32_t> r;

    cout << N << " " << T;
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << args[i] << " ";
        arg.pushBack(args[i]);
    }
    cout << endl;
//
//    for(int i = 0; i <N; i++ )
//    {
//        cout<<res[i]<<" ";
//        r.pushBack(res[i]);
//    }

    file.close();
}


int main() {

  // writeFiles("func.dat");

//    writeTest("second.dat");
   // readTest("third.dat");


//    int a,b;
//    cout<<"Enter range: ";
//    cin>>a>>b;

    cout<<"Your range is: [ "<<0<<" "<<10<<" ] ";
    cout<<endl;
    try {
        BinaryFileManager manager("TestFiles.dat");

        PolimorphicPtr func = manager.read("func.dat");

        //cout<<func->operator()(3);
        for(int i = 3; i < 10; i++){
            cout <<"f("<<i<<") = "<< func->operator()(i);
            cout<<endl;
        }

    }
    catch (const std::logic_error &err) {
        cout << err.what();

    }

}








//    try {
//        Function bebe = [](int x) {
//            Pair<bool,uint32_t> test(1,x * x);
//            return test;
//        };
//
//        bebe(4).first();
//
//        PartialFunction* ptr = new FunctionByCriteria<Function>(bebe);
//
//        PolimorphicPtr func1 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria(bebe));
//        PolimorphicPtr func2 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria([](int x) {
//            Pair<bool,uint32_t> test2(1,x * 2 - 1 );
//            return test2;
//        }));
//        PolimorphicPtr func3 = polymorphic_ptr<PartialFunction>(new FunctionByCriteria([](int x) {
//            Pair<bool,uint32_t> test2(1,x  + 5);
//            return test2;
//        }));
//
//
//        Vector<polymorphic_ptr<PartialFunction>> funcs;
//        funcs.pushBack(func1);
//        funcs.pushBack(func2);
//        funcs.pushBack(func3);
//
//        MaxFunctions maxFunc(funcs);
//        MinFunctions minFunc(funcs);
//
//     cout<< "This is the maximum result of your function: " << maxFunc(3) <<endl;
//     cout<< "and this is the min result of your functon: " << minFunc(3) <<endl;
//
//    }
//    catch (std::logic_error) {
//        cout << "Function is not defined here";
//    }
//    catch(...)
//    {
//        cout<<"Some error";
//    }




