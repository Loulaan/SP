cmake_minimum_required(VERSION 3.14)
project(Vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vector src/VectorImpl/Vector.hpp src/VectorImpl/Vector.h src/VectorImpl/testStreams.cpp)
