#pragma once
#include <cstdint>
#include <iostream>
#include <stdexcept>

const unsigned BITS = 8;


class MultiSet {

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

    //explicit MultiSet(unsigned n); ? nuzno li e
    MultiSet(unsigned n, unsigned k);
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);
    ~MultiSet();

    unsigned getCount(unsigned n) const;
    void add(unsigned n);

    void print()const;
    void printMem()const;



};

