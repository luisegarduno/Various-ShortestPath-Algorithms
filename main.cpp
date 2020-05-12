//
// Created by luise on 4/29/2020.
//

#include <iostream>
#include "FileReader.h"
#include "NetworkFile.h"
#include "Algorithm.h"
#include "MissingFilesException.h"

using namespace std;

int main(int argc,char * argv[]){

    try {
        // if argument counter != 2,throw custom exception
        if (argc != 1)
            throw MissingFilesException{};

        else{
            // FileReader will store the names of all files and create a set of 3 output files per input file
            auto * newFiles = new FileReader();

            // Iterate through input files  & create a NetworkFile object that holds corresponding output files
            for(auto i = newFiles->getInputFiles().begin(), j = newFiles->getOutputFiles().begin(); i != newFiles->getInputFiles().end(); ++i){
                Algorithm<string> * analyze = new NetworkFile<string>(*i, *j++, *j++, *j++);
                analyze->compute();

                delete analyze;
                //break;
            }

            delete newFiles;
        }
    }

    // catches custom exception message
    catch (MissingFilesException& e) {
        cout << MissingFilesException::what() << endl;
    }

    return 0;
}