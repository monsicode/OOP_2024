#include <iostream>
using namespace std;

using myfunc = bool (*)(char ch);

class ConsolePrinter{

    //bool (*censore)(char ch);

    myfunc censore;

public:

    ConsolePrinter():censore([](char ch){return false;}) {}
    ConsolePrinter(myfunc func):censore(func){}

    void print(const char* str) const
    {
        while(*str)
        {
            if(censore(*str))
                cout<<"*";
            else
                cout<<*str;
            str++;
        }
    }

};

class stringWrapper{

    const char* str;
    const ConsolePrinter& printer;

public:

  stringWrapper(const char* str, const ConsolePrinter& printer): str(str), printer(printer){}

  void print() const
  {
       printer.print(str);
  }


};

bool noA(char ch)
{
    return ch == 'a';
}

int  main(){

    ConsolePrinter pr(noA);
    ConsolePrinter pr1([](char ch){return ch =='l';});

    stringWrapper str({"hellaoolal"},pr1);

    str.print();

}