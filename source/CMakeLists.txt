cmake_minimum_required(VERSION 3.5)

project(2nd-term-algorithms)

set(SRC_LIST main.cpp dp.cpp brute-force.cpp bracket.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})