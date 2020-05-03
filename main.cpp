//
// Created by luise on 4/29/2020.
//

#include <iostream>

#include "FileReader.h"
#include "MissingFilesException.h"

using namespace std;

int main(int argc,char * argv[]){

    try {
        // if argument counter != 2,throw custom exception
        if (argc != 2)
            throw MissingFilesException{};

        else{
            auto * networkFile = new FileReader();
            networkFile->setCommands(argv[1]);
        }
    }

    // catches custom exception message
    catch (MissingFilesException& e) {
        cout << MissingFilesException::what() << endl;
    }

    return 0;
}