#include <iostream>
#include <cstring>

using printFunc = bool (*)(char ch);

struct Console_Printer{
    printFunc shouldCensore;

    Console_Printer(const printFunc& func):shouldCensore(func){}

    void print(const char* str) const
    {
        while(*str)
        {
            if(shouldCensore(*str))
            {
               std::cout<<'*';
            }
            else
                std::cout<<*str;

            str++;
        }

        std::cout<<std::endl;

    }

};

struct StringWrapper{
    char str[15] = {"Nana is baking"};

    const Console_Printer& printer;

    StringWrapper(const Console_Printer& printer): printer(printer){}

    void print() const{
        printer.print(str);
    }


};


int main() {

    Console_Printer printer([](char ch){return ch == 'a';});

    StringWrapper str(printer);
    str.print();

}
