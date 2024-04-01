#include "DynamicSet.h"


bool DynamicSet::isValidN(unsigned n) const
{
    return (n>1 && n<=1000);
}

unsigned DynamicSet::getBucketCount(unsigned n) const
{
    return n/8;
}

unsigned DynamicSet::getIndexAtBucket(unsigned n) const
{
    return n%8;
}

bool DynamicSet::contains(unsigned n) const
{
    unsigned bucketIndex = getBucketCount(n);
    unsigned indexBucket = getIndexAtBucket(n);

    unsigned mask = (1<<indexBucket);

    return buckets[bucketIndex] & mask;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
    bucketsCount = other.bucketsCount;
    buckets = new uint8_t [bucketsCount];

    for(int i = 0; i < bucketsCount; i++)
    {
        buckets[i] = other.buckets[i];
    }
}
void DynamicSet::free()
{
    delete[] buckets;
    bucketsCount = 0;

    buckets = nullptr;
}


DynamicSet::DynamicSet(unsigned n){
    if(isValidN(n))
    {
        bucketsCount = getBucketCount(n) + 1;
        buckets = new uint8_t[bucketsCount]{0};
        maxNum = n;
    }
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
    copyFrom(other);
}
DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
}
DynamicSet::~DynamicSet(){
    free();
};

void DynamicSet::print() const{
    for(int i = 0; i < maxNum; i++)
    {
        if(contains(i))
            std::cout<<i<<" ";
    }
}

void DynamicSet::add(unsigned n)
{
    unsigned bucketIndex = getBucketCount(n);
    buckets[bucketIndex]|=(1<<getIndexAtBucket(n));

}

void  DynamicSet::remove(unsigned n){

    unsigned bucketIndex = getBucketCount(n);
    buckets[bucketIndex]^=(1<<getIndexAtBucket(n));

}

DynamicSet& DynamicSet::Union(const DynamicSet& set)
{
    unsigned num = std::max(this->maxNum,set.maxNum);

    for(int i = 0; i < getBucketCount(num); i++)
    {
        this->buckets[i]|= set.buckets[i];
    }

    return *this;
}















