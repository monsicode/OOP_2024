#pragma once
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <fstream>


class MultiSet {
    const unsigned BITS = 8;

     uint8_t* data;

     unsigned n;
     unsigned bitsPerNumber; // k
     unsigned countBuckets; //elBucket*n
     unsigned numsInBucket;//8-k
     unsigned maxOccur; // 2^k - 1

     void copyFrom(const MultiSet& other);
     void free();

     unsigned getBucket(unsigned n) const;
     unsigned getIndex(unsigned n) const;
     void binaryPrinter(unsigned n)const;

public:
    
    MultiSet(unsigned n, unsigned k);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);
    ~MultiSet();

    unsigned getCount(unsigned n) const;
    void add(unsigned n);

    void print()const;
    void printMem()const;

    void serialize(const char* fileName) const;
   static MultiSet deserialize(const char* fileName);

    static MultiSet unionSet(const MultiSet& lhs, const MultiSet& rhs);
    static MultiSet intersectSets(const MultiSet& lhs, const MultiSet& rhs);
    static MultiSet difference(const MultiSet& lhs, const MultiSet& rhs);
    static MultiSet complement(const MultiSet& ms);


};

