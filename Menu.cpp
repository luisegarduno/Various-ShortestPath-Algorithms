//
// Created by Luis G. on 07/17/23.
//

#include "Menu.h"

/**
 * @brief Menu default constructor
 *
 */
Menu::Menu(){
    int algorithm_choice = 0, dataset_choice = 0;
    newFiles = new FileReader();

    while(true){
        algorithms_options();
        cin >> algorithm_choice;
        if(algorithm_choice == 6) break;
        clrscr();

        dataset_options();
        cin >> dataset_choice;
        if(newFiles->getDatasetNames().size() == dataset_choice + 1) break;
        clrscr();

        confirm_input(algorithm_choice, dataset_choice);
        break;
    }
}

/**
 * @brief Displays the user's input
 *
 * @param algorithm_choice the algorithm choice selected (1-5)
 * @param dataset_choice the dataset choice selected
 */
void Menu::confirm_input(int algorithm_choice, int dataset_choice){
    cout << "============================" << endl;
    cout << "You have selected:" << endl;

    cout << "Algorithm: ";
    switch(algorithm_choice){
        case 1:
            cout << "Depth First Search" << endl;
            break;
        case 2:
            cout << "Breadth First Search" << endl;
            break;
        case 3:
            cout << "Floyd-Warshall Search" << endl;
            break;
        case 4:
            cout << "Bellman-Ford Search" << endl;
            break;
        case 5:
            cout << "All Algorithms" << endl;
            break;
    }
    cout << "Dataset: " << newFiles->getDatasetNames()[dataset_choice - 1] << endl;
    cout << "============================" << endl;
}

/**
 * @brief Displays the algorithms options
 */
void Menu::algorithms_options(){
    cout << "============================" << endl;
    cout << "Select an algorithm to run:" << endl;
    cout << "1. Depth First Search" << endl;
    cout << "2. Breadth First Search" << endl;
    cout << "3. Floyd-Warshall Search" << endl;
    cout << "4. Bellman-Ford Search" << endl;
    cout << "5. All of the above" << endl;
    cout << "6. Exit" << endl;
    cout << "============================" << endl;
}

/**
 * @brief Displays the dataset options
 */
void Menu::dataset_options() {
    cout << "=================================" << endl;
    cout << "Select a dataset to use:" << endl;
    for(int i = 0; i < newFiles->getDatasetNames().size(); i++){
        cout << i + 1 << ". " << newFiles->getDatasetNames()[i] << endl;
    }
    cout << newFiles->getDatasetNames().size() + 1 << ". Exit" << endl;
    cout << "=================================" << endl;

}

/**
 * @brief Clears the terminal screen
 */
void Menu::clrscr(){
    cout << "\033[2J\033[1;1H";
}

/**
 * @brief Default destructor
 */
Menu::~Menu() = default;