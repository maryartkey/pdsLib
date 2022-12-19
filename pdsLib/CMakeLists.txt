# CMakeLists.txt for pdsLib

cmake_minimum_required(VERSION 3.10)

project(pdsLib)

add_executable (pdsLib "pdsLib.cpp" "HashTable.h" "Array.h" "List.h")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# TODO: Add tests and install targets if needed.
