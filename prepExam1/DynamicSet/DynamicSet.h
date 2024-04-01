#pragma once
#include <iostream>

class DynamicSet{
    uint8_t* buckets = nullptr;
    unsigned bucketsCount = 0;
    unsigned maxNum = 0;

    bool isValidN(unsigned n) const;
    unsigned getBucketCount(unsigned n) const;
    bool contains(unsigned n) const;

    unsigned getIndexAtBucket(unsigned n) const;

    void copyFrom(const DynamicSet& other);
    void free();

public:

    DynamicSet(unsigned n) ;
    DynamicSet(const DynamicSet& other);
    DynamicSet& operator=(const DynamicSet& other);
    ~DynamicSet();

    unsigned getCountBuckets() const{
        return bucketsCount + 1;
    }

    void print() const;

    void add(unsigned n);
    void remove(unsigned n);

    DynamicSet& Union(const DynamicSet& set);


};