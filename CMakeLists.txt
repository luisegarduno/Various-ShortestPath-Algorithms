cmake_minimum_required(VERSION 3.16)
project(ShortestPath)
set (EXE_NAME ShortestPath)

link_libraries(-lstdc++fs)

set (input01 "")
set (input02 "")
set (input03 "")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp MissingFilesException.h)

