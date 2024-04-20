#include "MultiSet.h"

void MultiSet::copyFrom(const MultiSet& other)
{
    n=other.n;
    bitsPerNumber = other.bitsPerNumber;
    countBuckets=other.countBuckets;
    numsInBucket=other.numsInBucket;
    maxOccur=other.maxOccur;

    data = new uint8_t [countBuckets];

    for(int i = 0; i < countBuckets + 1; i++)
        data[i] = other.data[i];

}
void MultiSet::free()
{
    delete[] data;

    data = nullptr;
    n = 0;
    countBuckets = 0;
    numsInBucket = 0;
    maxOccur = 0;
    bitsPerNumber = 0;
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

     this->n = n + 1;
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

    if(n >= this->n)
    {
        return 0;
    }

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
    for (int i = 0; i < n - 1; i++) {
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


void MultiSet::serialize(const char* fileName) const
{
     std::ofstream file(fileName, std::ios::binary);

     if(!file.is_open())
     {
         throw std::runtime_error("Could not open file");
     }

     file.write((const char*)&bitsPerNumber, sizeof(unsigned));
     file.write((const char*)&n, sizeof(unsigned));
     file.write((const char*)data, sizeof(unsigned) * countBuckets);

     file.close();

}



MultiSet MultiSet::deserialize(const char* fileName){
    std::ifstream file(fileName, std::ios::binary);

    if(!file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }

    unsigned n;
    unsigned bitsPerNumber;
    unsigned countBuckets;

    file.read((char*)&bitsPerNumber, sizeof(unsigned));
    file.read((char*)&n, sizeof(unsigned));

    MultiSet result(n, bitsPerNumber);

    file.read((char*)result.data, sizeof(unsigned) * countBuckets);


    return result;

    file.close();
}



MultiSet MultiSet::unionSet(const MultiSet& lhs, const MultiSet& rhs){
    unsigned maxN = std::max(lhs.n, rhs.n);
    MultiSet result(maxN, std::max(lhs.bitsPerNumber, rhs.bitsPerNumber));

        for (int i = 0; i < maxN; i++) {
        //unsigned countNum = lhs.getCount(i)+ rhs.getCount(i);
        unsigned countNum = std::max(lhs.getCount(i), rhs.getCount(i));

        for (int j = 0; j < countNum; j++)
        {
            result.add(i);
        }
    }

    return result;
}


MultiSet MultiSet::intersectSets(const MultiSet& lhs, const MultiSet& rhs){
    unsigned maxN = std::max(lhs.n, rhs.n);
    MultiSet result(maxN, std::max(lhs.bitsPerNumber, rhs.bitsPerNumber));

    for (int i = 0; i < maxN; i++) {
        //unsigned countNum = lhs.getCount(i)+ rhs.getCount(i);
        unsigned countNum = std::min(lhs.getCount(i), rhs.getCount(i));

        for (int j = 0; j < countNum; j++)
        {
            result.add(i);
        }
    }

    return result;
}

MultiSet MultiSet::difference(const MultiSet &lhs, const MultiSet &rhs){
    unsigned maxN = std::max(lhs.n, rhs.n);
    MultiSet result(maxN, std::max(lhs.bitsPerNumber, rhs.bitsPerNumber));

    for (int i = 0; i < maxN; i++) {
        //unsigned countNum = lhs.getCount(i)+ rhs.getCount(i);
        unsigned countNum = std::max((int)(lhs.getCount(i) - rhs.getCount(i)), 0);

        for (int j = 0; j < countNum; j++)
        {
            result.add(i);
        }
    }

    return result;
}

MultiSet MultiSet::complement(const MultiSet& ms){

    MultiSet result(ms.n, ms.bitsPerNumber);

    for (int i = 0; i < ms.n; ++i) {
       result.data[i] = ~ms.data[i];
    }

    return result;
}
