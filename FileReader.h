//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_FILEREADER_H
#define ALGORITHMS_FILEREADER_H

#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <bits/stdc++.h>

using std::ios;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::system;
using std::fstream;
using std::to_string;


class FileReader {
public:
    // Default constructor
    FileReader();

    // Used as constructor
    void setCommands(const char []);

    // Returns input/output file vectors as references
    vector<string>& getInputFiles();
    vector<string>& getOutputFiles();

    // Used to return the total amount of files in each vector
    int totalNumberOfInputFiles();
    int totalNumberOfOutputFiles();

    // FileReader Destructor
    ~FileReader();

private:
    // used to read in network data file names
    fstream cfin;

    // networkFile (name of given file in command line)
    string networkFile;

    // setter name for networksFile
    void setFileName(const char []);

    // Creates data set (3 .txt files) with each set having a specific ID at the front of the filename
    void addOutputFileSet(int);

    // inputFiles stores the string names of the given small, medium, and large network data files
    vector<string> inputFiles;

    // outputFiles stores the string names of the files inserted into the '/OutputFiles' folder
    vector<string> outputFiles;

};

#endif //ALGORITHMS_FILEREADER_H
