#include "Content.h"

char Content::getChar(size_t pos) const
{
    return text[pos];
}

Content::Content(){}

Content::Content(const char* fileName){
    readFrom(fileName);
}

void Content::readFrom(const char* fileName) {
    std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

    if (!ifs.is_open()) {
        std::cout << "File is not open!" << std::endl;
        return;
    }

    ifs.read(text, MAX_SIZE_CONTENT);

    ifs.close();
}


int Content::getCharPos(int k) const
{
    return k / 8;
}

void Content::changeKBit(unsigned k){

    for(int i = 0; i < MAX_SIZE_CONTENT; i+=k)
    {
        int pos = getCharPos(i);
        int posInMask = k % 8;

        text[pos] |= (1<<posInMask);
    }
}

void Content::mixWith(const Content& str){
    int sizeFirst = strlen(text);
    int sizeSecond = strlen(str.text);

    int minimum = sizeFirst > sizeSecond ? sizeSecond : sizeFirst;
    for (int i = 0; i < minimum;++i) {
        text[i] ^= str.getChar(i);
    }
}

void Content::saveTo(const char* fileName) const{
    std::ofstream ofs(fileName, std::ios::binary);

    if(!ofs.is_open())
    {
        std::cout<<"Error saving";
        return;
    }

    ofs.write((const char*)text, sizeof(text));
    ofs.close();

}

