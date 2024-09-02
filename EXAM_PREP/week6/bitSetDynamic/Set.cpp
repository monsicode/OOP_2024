#include "Set.h"

void Set::copyFrom(const Set &other) {
    size = other.size;

    data = new unsigned char [size];
    for(int i = 0; i < size; i++)
    {
      data[i] = other.data[i];
    }
}

void Set::free() {
    delete[] data;
    size = 0;
}

//im including 0 in the set
size_t Set::getBucket(size_t n) const {
   return n / 7;
}

size_t Set::getPosition(size_t n) const {
    return n % 8;
}


Set::Set(size_t n) {
    size_t buckets = getBucket(n);
    data = new unsigned char [buckets];
    for(int i = 0; i < buckets; i++)
        data[i] = 0;

    size = n;
}

void Set::add(size_t number) {
    if(number > size)
        return;

    size_t bucket = getBucket(number);
    size_t pos = getPosition(number);

    uint8_t mask = 0;
    mask = 1<<pos;

    data[bucket] |=mask;
}

bool Set::isIn(size_t number) const{
    size_t bucket = getBucket(number);
    size_t pos = getPosition(number);

    uint8_t mask = 0;
    mask = 1<<pos;

    return data[bucket] & mask;
}

void Set::printNumbers() const {
    for(int i = 0; i < size; i++)
    {
        if(isIn(i))
           std::cout<<i<<" ";
    }
}

void Set::printBits() const {
    for(int i = 0; i < size; i++)
    {
        if(isIn(i))
            std::cout<<1;
        else
            std::cout<<0;

//        if(i%8 == 0)
//            std::cout<<" ";
    }

}

Set unionSets(const Set &set1,const Set &set2) {
    size_t maxN = std::max(set1.size, set2.size);
    size_t minN = std::min(set1.size, set2.size);
    Set result(maxN);

    for(int i = 0; i < minN; i++)
    {
        result.data[i] = set1.data[i] | set2.data[i];
    }

    if(set1.size < set2.size)
    {
        for(int i = minN; i < maxN; i++)
        {
            result.data[i] = set2.data[i];
        }
    }
    else {
        for(int i = minN; i < maxN; i++)
        {
            result.data[i] = set1.data[i];
        }
    }

    return result;
}

Set intersect(const Set &set1,const Set &set2) {
    Set result(std::min(set1.size, set2.size));

    for(int i = 0; i < result.size; i++)
    {
        result.data[i] = set1.data[i] & set2.data[i];
    }

    return result;
}

Set::Set(const Set & set) {
    copyFrom(set);
}

Set &Set::operator=(const Set & other) {
    if(this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Set::~Set() {
 free();
}

