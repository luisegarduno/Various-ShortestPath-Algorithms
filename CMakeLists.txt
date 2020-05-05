cmake_minimum_required(VERSION 3.10)
project(Algorithms)
set (EXE_NAME FinalProject)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....
set (input01 "InputFiles/networks.txt")
set (input02 "InputFiles/moreno_kangaroo.txt")
set (input03 "InputFiles/moreno_macaques.txt")
set (input04 "InputFiles/opsahl-usairport.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp FileReader.cpp FileReader.h Graph.h Vertex.cpp Vertex.h MissingFilesException.h Node.h LinkedList.h Edge.cpp Edge.h Algorithm.h NetworkFile.h Algorithm.h)
