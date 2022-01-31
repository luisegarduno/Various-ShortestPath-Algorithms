cmake_minimum_required(VERSION 3.10)
project(Various-ShortestPath-Algorithms)
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
add_executable(${EXE_NAME} main.cpp FileReader.cpp FileReader.h Graph.h Vertex.cpp Vertex.h MissingFilesException.h Node.h LinkedList.h Edge.cpp Edge.h Algorithm.h NetworkFile.h Algorithm.h BellmanFord.h FloydWarshall.h)

