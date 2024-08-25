#pragma once
#include <iostream>

class StringPool{

public:
    StringPool();

    StringPool(const StringPool& other) = delete;
    StringPool& operator=(const StringPool& other) = delete;

   ~StringPool();

   const char* getAllocatedString(const char* str);
   unsigned release(const char* str);

private:
    struct StringRecord{
        char* data = nullptr;
        unsigned refCount = 0;
    };


    StringRecord* stringRecords;

    size_t countStrings;
    size_t capacity;


    unsigned allocateString(const char* str);
    void remove(const char* str);
    int findString(const char* str) const;

    void resize();
};