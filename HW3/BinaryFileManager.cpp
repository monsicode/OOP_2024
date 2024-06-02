#include "BinaryFileManager.h"

uint32_t BinaryFileManager::readUint(std::ifstream& file){
    uint32_t result;
    file.read((char*)&result, sizeof(uint32_t));

    return result;
}

BinaryFileManager::BinaryFileManager(const char* fileName){

}

void BinaryFileManager::read(const char* fileName){
    std::ifstream file(fileName, std::ios::binary);

    if(!file.is_open())
        throw std::ios_base::failure("Error opennig the file");

    uint32_t N = readUint(file);;
    uint32_t T = readUint(file);

    switch (T) {
        case 0:{
            Vector<uint32_t> args(N);
            Vector<uint32_t> res(N);

            for (uint16_t i = 0; i < N; ++i) {
                args[i] = readUint(file);
            }
            for (uint16_t i = 0; i < N; ++i) {
                res[i] = readUint(file);
            }

            CaseZeroFunction functionZero(args,res,N);
            polymorphic_ptr<PartialFunction>(new FunctionByCriteria(functionZero));

           };


        }
        case 1:{

        }

    }


}

void BinaryFileManager::write(const char* fileName) const
{

}