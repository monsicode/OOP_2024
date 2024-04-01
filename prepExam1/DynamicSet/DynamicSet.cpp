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


bool DynamicSet::inInterval(unsigned n) const
{

}

void DynamicSet::print() const{
    for(int i = 0; i < maxNum; i++)
    {
        if(contains(i))
            std::cout<<i<<" ";
    }
}

void  DynamicSet::printMem() const{
    for(int i = 0; i < maxNum; i++)
    {
        if(i%8==0 && i!=0)
            std::cout<<" ";

        std::cout<<contains(i);
    }

    for(int i = 0; i < 8 - maxNum%8; i++) {
        std::cout<<0;
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

DynamicSet Union(const DynamicSet& set1, const DynamicSet& set2)
{
    unsigned size = std::max(set1.maxNum,set2.maxNum);
    DynamicSet result(size);

    unsigned minSize = std::min(set1.bucketsCount,set2.bucketsCount);

    for (int i = 0; i < minSize; ++i)
    {
        result.buckets[i] = set1.buckets[i] | set2.buckets[i];
    }

    if(set1.maxNum > set2.maxNum)
    {
        for (int i =  minSize; i < set1.bucketsCount; ++i)
        {
            result.buckets[i]|= set1.buckets[i];
        }
    }

    else if(set1.maxNum < set2.maxNum)
    {
        for (int i =  minSize; i < set2.bucketsCount; ++i)
        {
            result.buckets[i]|= set2.buckets[i];
        }
    }

    return result;

}

DynamicSet Intersect(const DynamicSet& set1, const DynamicSet& set2)
{
    unsigned size = std::min(set1.maxNum,set2.maxNum);
    DynamicSet result(size);

    unsigned minSize = std::min(set1.bucketsCount,set2.bucketsCount);

    for (int i = 0; i < minSize; ++i)
    {
        result.buckets[i] = set1.buckets[i] & set2.buckets[i];
    }

    return result;

}













