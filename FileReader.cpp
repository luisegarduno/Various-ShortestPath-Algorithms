//
// Created by Luis G. on 07/16/23.
//

#include "FileReader.h"


/* 1. Allow user to drop dataset/s into a folder called InputFiles (or can be called anything)
 * 2. Scan folder & retrieve all file names.
 * 3. Ask the user what algorithm they want to run.
 * 4. Scan the datasets and determine which datasets can be used given the algorithm specified by the user.
 *
 *
 * Example:
 * $ ./ShortestPath
 *
 * "Select an algorithm to run:
 *
 */

// Default Constructor
FileReader::FileReader() {
    const char * folder_name = "../InputFiles/";
    fs::path folder = folder_name;

    fetchFileNames(folder);
}

// Iterates through folder and stores the full file path and file (datasets) names in vectors
void FileReader::fetchFileNames(const fs::path& folder_name){
    for (const auto& entry : fs::directory_iterator(folder_name)){
        inputFilePaths.push_back(entry.path());
        inputFileNames.push_back(parseFilePath(entry.path()));
    }
}


// Parses the file path and returns the file name
string FileReader::parseFilePath(string file_path) {
    string file_name = "";

    // Iterate through string backwards and stop when '/' is found
    for(int i = file_path.size() - 1; i >= 0; i--){
        if(file_path[i] == '/'){
            break;
        }
        file_name.insert(0,1,file_path[i]);
    }

    return file_name;
}

// Returns the dataset names
vector<string> FileReader::getDatasetNames() {
    return inputFileNames;
}

// Returns the dataset file paths
vector<string> FileReader::getDatasetPaths() {
    return inputFilePaths;
}

// Destructor
FileReader::~FileReader() {

}