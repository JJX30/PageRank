cmake_minimum_required(VERSION 3.22)
project(PageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(PageRank main.cpp AdjacencyList.cpp AdjacencyList.h)
