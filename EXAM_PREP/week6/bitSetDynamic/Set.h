#pragma once
#include <iostream>

class Set{
    unsigned char* data;
    size_t size;

    void copyFrom(const Set& other);
    void free();

    size_t getBucket(size_t n) const;
    size_t getPosition(size_t) const;

public:
    Set(size_t n);

    void add(size_t number);
    bool isIn(size_t number) const;

    void printNumbers() const;
    void printBits() const;

    Set(const Set&);
    Set& operator=(const Set&);
    ~Set();


    friend Set unionSets(const Set &set1, const Set& set2);
    friend Set intersect(const Set &set1, const Set& set2);

};

