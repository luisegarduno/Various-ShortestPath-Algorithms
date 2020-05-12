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
#include <sstream>
#include <iostream>
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>
#include <unordered_set>
#include <bits/stdc++.h>
#include "rapidjson/document.h"
#include <experimental/iterator>
#include <experimental/filesystem>
#include "rapidjson/filereadstream.h"

using namespace rapidjson;
namespace filesystem = std::experimental::filesystem;

using std::copy;
using std::fopen;
using std::string;
using std::ifstream;
using std::remove_if;
using std::istringstream;
using std::unordered_set;
using std::ostream_iterator;


using std::ios;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::fstream;
using std::to_string;


class FileReader {
    public:
        // Default constructor
        FileReader();

        static void parseCurrentFile(const filesystem::path&);

        static string parsePathName(string);

        // Uses path name to open up JSON file, the doing the following:
        // 1st) <rapidjson> library is used to parse JSON file properly.
        // 2nd) stripHTML member function is called to remove all HTML from section
        // 3rd) split2Word, which aside from splitting a section to individual words,
        //  it additionally makes every word lowercase & removes stopwords, & stems words
        void parseJSON(filesystem::path);

        // Returns total number of documents word was
        // found in
        int getTotDocsFound();

        // used as a flag, to let program know when the file is invalid
        // make `fileIsValidFlag` equal to false;
        bool fileIsValidFlag;

        // Used as constructor
        void setCommands(string);

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
        void setFileName(string);

        // Creates data set (3 .txt files) with each set having a specific ID at the front of the filename
        void addOutputFileSet(int);

        // inputFiles stores the string names of the given small, medium, and large network data files
        vector<string> inputFiles;

        // outputFiles stores the string names of the files inserted into the '/OutputFiles' folder
        vector<string> outputFiles;

        // Total number of documents the search
        // word was found in
        int totDocsFound;

};

#endif //ALGORITHMS_FILEREADER_H
