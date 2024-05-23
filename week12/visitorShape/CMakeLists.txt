cmake_minimum_required(VERSION 3.25)
project(visitorShape)

set(CMAKE_CXX_STANDARD 17)

add_executable(visitorShape main.cpp Shape.cpp Shape.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h)
