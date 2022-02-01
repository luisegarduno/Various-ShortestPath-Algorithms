//
// Created by luise on 5/3/2020.
//

#include "FileReader.h"

// Default constructor
FileReader::FileReader(): networkFile("") {
    auto inputFiles_folder = "InputFiles/";
    filesystem::path file_name = inputFiles_folder;

    if (file_name == "") {
        cout << "Directory Error: Invalid path to a folder, exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    parseCurrentFile(file_name);

    string networkFiles = file_name.generic_string();
    networkFiles.pop_back();
    setCommands(networkFiles + "networks.txt");
}

void FileReader::setCommands(string file_name) {
    setFileName(std::move(file_name));

    // Creates a directory called "/OutputFiles" if it does not
    // already exist.
    if (mkdir("OutputFiles", 0777) == -1){
        cerr << "Error : " << strerror(errno) << " : 'OutputFiles' Folder" << endl;
    }

    // Iterate through the file given in the command line and
    // create output files for each size/algorithm.
    // Store input files and output file names in separate vectors
    string filename, tempFilename;

    // fileID of type integer helps keep count just in case there are more than 3 inputted network data files
    int fileID = 1;
    while (!cfin.eof()) {

        // Creates a set of 3 .txt files for each file
        cfin >> filename;
        if(tempFilename != filename){
            inputFiles.push_back(filename);

            addOutputFileSet(fileID);
            fileID++;
        }
        tempFilename = filename;
    }
    cfin.close();
}

// setFileName sets the given file name in the command line to the main file as well as checking if it is the
// correct format type.
void FileReader::setFileName(string filename){
    networkFile = std::move(filename);

    int outputFilename_size  = networkFile.size();

    // Create a backupnetworkFile (simple original filename with .txt added to the end)
    string backupnetworkFile = networkFile + ".txt";


    // Save the last 4 characters of the string to verify it is a .txt file
    string file_extension;
    for(int i = 4; i > 0; i--){
        file_extension += networkFile[outputFilename_size - i];
    }

    // if given file does not have .txt file extension, set networkFile equal to the backupnetworkFile
    if(file_extension != ".txt"){
        cfin.open(backupnetworkFile.c_str());
        if(!cfin.is_open()){
            cout << "'" << networkFile << "' or '" << backupnetworkFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
        networkFile = backupnetworkFile;
    }
    else{
        cfin.open(networkFile.c_str());
        if(!cfin.is_open()){
            cout << "'" << networkFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
    }
}

// addOutputFileSet creates a set of 3 output files with a custom ID number at the front
void FileReader::addOutputFileSet(int fileID) {
    string tempFilename;

    // FILE *fp = fopen( ("OutputFiles/" + tempFilename).c_str(), "w+"); fclose(fp);

    {   tempFilename = to_string(fileID) + "_Trivial.txt";
        outputFiles.push_back(tempFilename);
        fstream newFile(("OutputFiles/" + tempFilename).c_str(), ios::out);  }

    {   tempFilename = to_string(fileID) + "_BellmanFord.txt";
        outputFiles.push_back(tempFilename);
        fstream newFile(("OutputFiles/" + tempFilename).c_str(), ios::out);  }

    {   tempFilename = to_string(fileID) + "_FloydWarshall.txt";
        outputFiles.push_back(tempFilename);
        fstream newFile(("OutputFiles/" + tempFilename).c_str(), ios::out);  }

}

// Returns inputFiles vector as reference
vector<string>& FileReader::getInputFiles(){
    return this->inputFiles;
}

// Returns outputFiles vector as reference
vector<string>& FileReader::getOutputFiles(){
    return this->outputFiles;
}

void FileReader::parseCurrentFile(const filesystem::path& fileName){
    filesystem::directory_iterator end;
    fstream fout;

    string networksData_Files = fileName.generic_string();
    networksData_Files.pop_back();
    networksData_Files += "networks.txt";

    fout.open(networksData_Files.c_str(), std::ios::out);
    if (!fout.is_open()) {
        cout << "'" << networksData_Files << "' could not be opened. Please check input files." << endl;
        exit(-1);
    }
    string tempFile;

    for(filesystem::directory_iterator theIterator(fileName) ; theIterator!= end; ++theIterator){
        // directory iterator is first converted to a path
        filesystem::path dirToPath = *theIterator;
        tempFile = dirToPath.generic_string();

        if(tempFile != "InputFiles/networks.txt"){
            tempFile = "/" + parsePathName(tempFile);
            tempFile = parsePathName(tempFile);
            tempFile.erase(0,1);
            fout << tempFile << endl;
        }
    }
    fout.close();
}

string FileReader::parsePathName(string section){
    for(size_t start = 0; start < section.size(); start++){
        if(section[start] == '/'){
            size_t end = start + 1;

            while(section[end] != '/' && end < section.size()){
                end++;
                if(end == section.size()){
                    return section;
                }
            }
            section.erase(start, end - start);
            start--;
        }
    }

    return section;
}

// FileReader destructor
FileReader::~FileReader()= default;
