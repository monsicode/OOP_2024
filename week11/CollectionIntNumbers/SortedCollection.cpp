#include "SortedCollection.h"

int SortedCollection::lowerBound(int x) const {
    int left = 0;
    int right = size - 1;

    int indexToReturn = -1;

    while (left <= right) {
        //to prevent int overflow
        int mid = (right - left) / 2 + left;

        if (data[mid] == x) {
            // за да се уверим че е най-левия, продължаваме търсенето в лявата половина
            indexToReturn = mid;
            right = mid - 1;
        }
        else if (data[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return indexToReturn;
}

int SortedCollection::upperBound(int x) const {

    int left = 0;
    int right = size - 1;

    int indexToReturn = -1;

    while(left <= right)
    {

        int mid = left + (right - left)/2;

        if(data[mid] == x)
        {
            indexToReturn = mid;
            left = mid + 1;
        }
        else if(data[mid] < x)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return indexToReturn;
}

void SortedCollection::add(int num) {

    if(size == capacity)
        resize();

    int ind = size;

    //insertion sort
    while( ind != 0 && data[ind - 1] > num)
    {
        data[ind] = data[ind - 1];
        ind--;
    }

    data[ind] = num;
    size++;
}

void SortedCollection::remove(int num) {
    int indLow = lowerBound(num);

    if(indLow == size)
        return;

    for (int i = indLow; i < size; ++i) {
        std::swap(data[indLow], data[i]);
        indLow =i;
    }
    size--;

}
unsigned SortedCollection::getCount(int num) const {
    int indLow = lowerBound(num);
    int indHigh = upperBound(num);

    if (indLow == -1)
    {
        return 0;
    }

    return indHigh - indLow + 1;

}
bool SortedCollection::isIn(int num) const {
   return lowerBound(num) > 0;
}
