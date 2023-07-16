cmake_minimum_required(VERSION 3.24)
project(L4)

set(CMAKE_CXX_STANDARD 20)

add_executable(L4 Shop.cpp Controller.cpp Repository.cpp UI.cpp Domain.h Repository.h Controller.h UI.h Domain.cpp)
