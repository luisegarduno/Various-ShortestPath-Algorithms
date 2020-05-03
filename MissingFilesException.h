//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_MISSINGFILESEXCEPTION_H
#define ALGORITHMS_MISSINGFILESEXCEPTION_H

// Custom exception used only at the start of the program when checking
// whether or not the valid number of files are entered into the command line
class MissingFilesException{
    public:
        static const char * what() {
            return "Missing/invalid number of arguments";
        }
};

#endif //ALGORITHMS_MISSINGFILESEXCEPTION_H
