#include "BinaryFileManager.h"

uint32_t BinaryFileManager::readUint(std::ifstream &file)  {
    uint32_t result;
    file.read((char *) &result, sizeof(uint32_t));

    return result;
}

const char* BinaryFileManager::readString(std::ifstream& file)  {
    int length;
    file.read((char*)&length, sizeof(int));

    char* arr = new char[length];
    file.read(arr, length);

    return arr;
}

polymorphic_ptr<PartialFunction> BinaryFileManager::read(const char *fileName) {
    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open())
        throw std::ios_base::failure("Error opening the file");

    uint32_t N = readUint(file);
    uint32_t T = readUint(file);

    switch (T) {
        case 0: {
            Vector<uint32_t> args;
            Vector<uint32_t> res;

            for (uint16_t i = 0; i < N; ++i) {
                args.pushBack(readUint(file));
            }
            for (uint16_t i = 0; i < N; ++i) {
                res.pushBack(readUint(file));
            }

            CaseZeroFunction functionZero(args, res, N);
            return PolimorphicPtr(new FunctionByCriteria(functionZero));

        }

        case 1:
        {
            Vector<uint32_t> args;

            for (uint16_t i = 0; i < N; ++i) {
                args.pushBack(readUint(file));
            }

            CaseOneFunction functionOne(args,N);
            return PolimorphicPtr(new FunctionByCriteria(functionOne));
        }

        case 2:
        {
            Vector<uint32_t> args;

            for (uint16_t i = 0; i < N; ++i) {
                args.pushBack(readUint(file));
            }

            CaseTwoFunction functionTwo(args,N);
            return PolimorphicPtr (new FunctionByCriteria(functionTwo));
        }

        case 3:
        {
            Vector<PolimorphicPtr> functions;

            for (uint16_t i = 0; i < N ; ++i) {
               const char* path = readString(file);
               functions.pushBack(read(path));
            }

            return PolimorphicPtr (new MaxFunctions(functions));
        }

        case 4:
        {
            Vector<PolimorphicPtr> functions;

            for (uint16_t i = 0; i < N ; ++i) {
                const char* path = readString(file);
                functions.pushBack(read(path));
            }

            return PolimorphicPtr (new MinFunctions(functions));
        }
    }

    file.close();
}
