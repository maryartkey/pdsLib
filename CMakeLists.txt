cmake_minimum_required (VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#-----------------------------------------#

project(pdsLib VERSION 1.0 LANGUAGES CXX)

add_executable(pdsLib src/main.cpp)

add_library(pdsLib-lib INTERFACE)

target_include_directories(pdsLib-lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(pdsLib-lib INTERFACE cxx_std_14)

add_library(pdsLib::library ALIAS pdsLib-lib)

#------------------test-------------------#

add_subdirectory(test)

#------------------docs-------------------#

add_subdirectory(doc)

#-----------------------------------------#


