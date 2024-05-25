#include "NormalCollection.h"

void NormalCollection::add(int num) {
    if(size == capacity)
        resize();

       data[size++] = num;
}
void NormalCollection::remove(int num) {
//защо толкова дълъг код има за remove в github
    for(int i = 0; i < size; i++)
    {
        if(data[i] == num)
            std::swap(data[i], data[size - 1]);
            size--;
            break;
    }

}
unsigned NormalCollection::getCount(int num) const {

    unsigned count = 0;

    for(int i = 0; i < size; i++) {
        if(data[i] == num)
            count++;
    }

    return count;
}
bool NormalCollection::isIn(int num) const {
    // не можем ли така да преизползваме функцията?
    if(getCount(num) > 0)
        return true;
    return false;
}
