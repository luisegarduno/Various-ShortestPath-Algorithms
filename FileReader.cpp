//
// Created by luise on 5/3/2020.
//

#include "FileReader.h"

// Default constructor
FileReader::FileReader(): networkFile(""){
}

void FileReader::setCommands(const char argv[]) {
    setFileName(argv);

    // Creates a directory called "/OutputFiles" if it does not
    // already exist.
    if(!mkdir("OutputFiles",0)){
        mkdir("OutputFiles", 0);
    }

    // Iterate through the file given in the command line and
    // create output files for each size/algorithm.
    // Store input files and output file names in separate vectors
    string filename, tempFilename;

    // fileCounter of type integer helps keep count just in case there are more than 3 inputted network data files
    int fileCounter = 1;
    while (!cfin.eof()) {
        cfin >> filename;

        if(filename == "[Small_Input]"){
            cfin >> filename;
            inputFiles.push_back(filename);

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_Trivial.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/1_BellmanFord.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/1_FloydWarshall.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            fileCounter++;
        }

        if(filename == "[Medium_Input]"){
            cfin >> filename;
            inputFiles.push_back(filename);

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_Trivial.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_BellmanFord.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_FloydWarshall.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            fileCounter++;
        }

        if(filename == "[Large_Input]"){
            cfin >> filename;
            inputFiles.push_back(filename);

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_Trivial.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_BellmanFord.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            {   tempFilename = "OutputFiles/" + to_string(fileCounter) + "_FloydWarshall.txt";
                fstream newFile(tempFilename, ios::out);
                outputFiles.push_back(tempFilename);}

            fileCounter++;
        }
    }

    cfin.close();
}

// setFileName sets the given file name in the command line to the main file as well as checking if it is the
// correct format type.
void FileReader::setFileName(const char filename[]){
    networkFile = filename;

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

// Returns total number of provided files
int FileReader::totalNumberOfInputFiles() {
    return inputFiles.size();
}
// Returns total number of files created in /OutputFiles folder
int FileReader::totalNumberOfOutputFiles() {
    return outputFiles.size();
}

// Returns inputFiles vector as reference
vector<string>& FileReader::getInputFiles(){
    return this->inputFiles;
}

// Returns outputFiles vector as reference
vector<string>& FileReader::getOutputFiles(){
    return this->outputFiles;
}

// FileReader destructor
FileReader::~FileReader()= default;
