cmake_minimum_required(VERSION 3.10)
project(ServerUDP)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
link_directories(/usr/local/opt/llvm/lib)

add_executable(ServerUDP main.cpp Server.cpp Server.h port.h CityConnections.cpp CityConnections.h City.cpp City.h SearchPath.cpp SearchPath.h PairPathCost.cpp PairPathCost.h Search.cpp Search.h)