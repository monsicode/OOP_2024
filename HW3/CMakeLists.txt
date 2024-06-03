cmake_minimum_required(VERSION 3.25)
project(HW3)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW3 main.cpp PartialFunction.cpp PartialFunction.h Pair.hpp FunctionByCriteria.hpp Vector.hpp polymorphic_ptr.hpp ConteinerFunctions.cpp ConteinerFunctions.h MaxFunctions.cpp MaxFunctions.h MinFunctions.cpp MinFunctions.h BinaryFileManager.cpp BinaryFileManager.h CaseZeroFunction.cpp CaseZeroFunction.h CaseOneFunction.cpp CaseOneFunction.h CaseTwoFunction.cpp CaseTwoFunction.h)
