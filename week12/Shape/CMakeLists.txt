cmake_minimum_required(VERSION 3.25)
project(Shape_visitor)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shape_visitor main.cpp Shape.cpp Shape.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h CollectionShape.cpp CollectionShape.h ShapeFactory.cpp ShapeFactory.h)
