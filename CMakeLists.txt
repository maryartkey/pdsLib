cmake_minimum_required (VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#----------------project--------------------#

project(pdsLib VERSION 1.0 LANGUAGES CXX)

#------------create static lib--------------#

add_library(pdsLib_lib STATIC src/source.cpp src/Array.h)

target_include_directories(pdsLib_lib PUBLIC ./src)

add_executable(pdsLib_a src/main.cpp)

target_link_libraries(pdsLib_a PRIVATE pdsLib_lib)

#--------------create dll lib---------------#

add_library(pdsLib_dll SHARED src/source.cpp)

target_include_directories(pdsLib_dll PUBLIC ./src)

add_executable(pdsLib_d src/main.cpp)

target_link_libraries(pdsLib_d PRIVATE pdsLib_dll)


#-------------------test-------------------#

add_subdirectory(test)

#-------------------docs-------------------#

#add_subdirectory(doc)

#------------------------------------------#