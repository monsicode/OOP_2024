cmake_minimum_required(VERSION 3.25)
project(Shared_ptr)

set(CMAKE_CXX_STANDARD 17)

add_executable(Shared_ptr main.cpp Shared_ptr.hpp Weak_ptr.hpp)
