//
// Created by Luis G. on 07/17/2023.
//

#ifndef SHORTESTPATH_MENU_H
#define SHORTESTPATH_MENU_H

#include <iostream>
#include "FileReader.h"

using std::cin;
using std::cout;
using std::endl;

class Menu{
    public:
        // Default constructor
        Menu();

        // Displays the user's input
        void confirm_input(int algorithm_choice, int dataset_choice);

        // Displays the algorithms options
        void algorithms_options();

        // Displays the dataset options
        void dataset_options();

        // Clears the terminal screen
        void clrscr();

        // Menu destructor
        ~Menu();

    private:
        FileReader * newFiles;
};


#endif //SHORTESTPATH_MENU_H
