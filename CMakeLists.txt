cmake_minimum_required(VERSION 3.5)

project(binary_tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")

add_executable(binary_tree ${SOURCES} ${HEADERS} main.cpp)

install(TARGETS binary_tree
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
