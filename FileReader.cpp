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

/**
 * @brief FileReader default constructor
 *
 */
FileReader::FileReader() {
    const char * folder_name = "../InputFiles/";
    fs::path folder = folder_name;

    fetchFileNames(folder);
}

/**
 * @brief Reads files in the InputFiles folder and stores the
 * full file path location and file names in vectors
 *
 * @param folder_name the folder name where the datasets are stored
 */
void FileReader::fetchFileNames(const fs::path& folder_name){
    for (const auto& entry : fs::directory_iterator(folder_name)){
        inputFilePaths.push_back(entry.path());
        inputFileNames.push_back(parseFilePath(entry.path()));
    }
}

/**
 * @brief Removes the file path and returns the file name
 *
 * @param file_path the file path to be parsed
 * @return string the file name
 */
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

/**
 * @brief Returns the dataset names
 *
 * @return vector<string> the dataset names
 */
vector<string> FileReader::getDatasetNames() {
    return inputFileNames;
}

/**
 * @brief Returns the dataset file paths
 *
 * @return vector<string> the dataset file paths
 */
vector<string> FileReader::getDatasetPaths() {
    return inputFilePaths;
}

/**
 * @brief FileReader destructor
 *
 */
FileReader::~FileReader() {
}