//
// Created by Luis G. on 7/16/23.
//

#ifndef SHORTESTPATH_FILEREADER_H
#define SHORTESTPATH_FILEREADER_H

#include <vector>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;
using std::endl;
using std::string;
using std::vector;

class FileReader {
    public:
        // Default constructor
        FileReader();

        // Reads files in the InputFiles folder and stores the
        // full file path location and file names in vectors
        void fetchFileNames(const fs::path& folder_name);

        // Removes the file path and returns the file name
        string parseFilePath(string file_path);

        // Returns the dataset names
        vector<string> getDatasetNames();

        // Returns the dataset file paths
        vector<string> getDatasetPaths();

        // FileReader destructor
        ~FileReader();

    private:

        // inputFilesNames stores the string names of the given data files
        vector<string> inputFileNames;

        // inputFilePaths stores the full file path location of the given data files
        vector<string> inputFilePaths;
};

#endif // SHORTESTPATH_FILEREADER_H
