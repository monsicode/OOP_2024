#include "IntervalCollection.h"

bool IntervalCollection::isInInterval(int num) const {
    return num>=start && num <= end;
}

IntervalCollection::IntervalCollection(int start, int end)
{
    this->start = start;
    this->end = end;
}

void IntervalCollection::add(int num) {
    if(!isInInterval(num))
        throw std::out_of_range("Out of range!");

    data[size++] = num;
}
void IntervalCollection::remove(int num) {

}
unsigned IntervalCollection::getCount(int num) const {

}
bool IntervalCollection::isIn(int num) const {

}