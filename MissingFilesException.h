//
// Created by Luis G. on 07/29/2023.
//

#ifndef SHORTESTPATH_MISSINGFILESEXCEPTION_H
#define SHORTESTPATH_MISSINGFILESEXCEPTION_H

/**
 * Custom exception used only at the start of the program when checking
 * whether or not the valid number of files are entered into the command line
 */
class MissingFilesException{
    public:
        static const char * what() {
            return "Missing/invalid number of arguments";
        }
};

#endif //SHORTESTPATH_MISSINGFILESEXCEPTION_H
