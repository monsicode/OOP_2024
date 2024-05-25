cmake_minimum_required(VERSION 3.25)
project(CollectionIntNumbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(CollectionIntNumbers main.cpp Collection.cpp Collection.h DynamicNum.cpp DynamicNum.h NormalCollection.cpp NormalCollection.h SortedCollection.cpp SortedCollection.h IntervalCollection.cpp IntervalCollection.h)
