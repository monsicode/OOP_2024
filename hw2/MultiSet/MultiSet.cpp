#include "MultiSet.h"

void MultiSet::copyFrom(const MultiSet& other)
{
    n=other.n;
    countBuckets=other.countBuckets;
    numsInBucket=other.numsInBucket;
    maxOccur=other.maxOccur;

    data = new uint8_t [countBuckets];

    for(int i = 0; i < countBuckets; i++)
        data[i] = other.data[i];

}
void MultiSet::free()
{
    delete[] data;

    data = nullptr;
    n=0;
    countBuckets=0;
    numsInBucket=0;
    maxOccur=0;
}


unsigned MultiSet::getBucket(unsigned n) const{
    return n / numsInBucket;
}

unsigned MultiSet::getIndex(unsigned n) const{
    return (n % numsInBucket) * bitsPerNumber;
}

void MultiSet::binaryPrinter(unsigned n)const{
    for (int i = bitsPerNumber - 1 ; i >= 0; --i) {
        std::cout << ((n >> i) & 1);
    }
}


MultiSet::MultiSet(unsigned n, unsigned k){

     this->n = n;
     bitsPerNumber = k;
     maxOccur = (1<<k) - 1; // 2^k - 1
     numsInBucket = BITS / k ;
     countBuckets = n / numsInBucket + 1; // +1 in case the number is odd

    data = new uint8_t[countBuckets]{0};

}

MultiSet::MultiSet(const MultiSet& other){
    copyFrom(other);
}
MultiSet& MultiSet::operator=(const MultiSet& other){
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
MultiSet::~MultiSet(){
    free();
}

unsigned MultiSet::getCount(unsigned n) const{
    unsigned bucket = getBucket(n);
    unsigned index = getIndex(n);

    unsigned mask  = maxOccur;
    mask <<= index;

    return (data[bucket] & mask) >> index;
}

void MultiSet::add(unsigned n){

    unsigned count = getCount(n);

    if(count >= maxOccur)
    {
        throw std::out_of_range("Out of range");
    }

    unsigned bucket = getBucket(n);
    unsigned index = getIndex(n);

    unsigned mask  = maxOccur;
    mask <<= index;
    mask = ~mask;

    data[bucket] &= mask;
    count++;
    count <<= index;
    data[bucket] |= count;
}


void MultiSet::print()const{
    for (int i = 0; i < n; i++) {
        unsigned count  = getCount(i);
        for (int j = 0; j < count ; j++)
        {
           std::cout<<i<<" ";
        }
    }
}
void MultiSet::printMem()const{
    for (int i = 0; i < n; i++){
        binaryPrinter(getCount(i));
        std::cout<<" ";
    }
}

