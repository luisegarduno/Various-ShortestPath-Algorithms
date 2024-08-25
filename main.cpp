//
// Created by luise on 4/29/2020.
//

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Menu.h"
#include "catch.hpp"
#include "MissingFilesException.h"

using namespace std;

#define TEST true

/**
 * @brief Runs test.cpp using Catch2 library
 *
 * @param argc int - number of arguments
 * @param argv char* - argument vector
 * @return Catch::Session().run(argc, argv)
 */
int runCatchTests(int argc, char * argv[]) {
    return Catch::Session().run(argc, argv);
}

int main(int argc,char * argv[]){

    try {
        // if argument counter != 2,throw custom exception
        if (argc != 1)
            throw MissingFilesException{};

        else{
            Menu * menu;

            // Testing (Workflow) - TDD w/ Catch
            if(TEST){
                runCatchTests(argc, argv);

                menu = new Menu(false);
                delete menu;
            }
            else {
                /* ============ Production ================= */
                menu = new Menu();
                delete menu;
            }
        }
    }

    // catches custom exception message
    catch (MissingFilesException& e) {
        cout << MissingFilesException::what() << endl;
    }

    return 0;
}