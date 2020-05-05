//
// Created by luise on 5/5/2020.
//

#ifndef ALGORITHMS_NETWORKFILE_H
#define ALGORITHMS_NETWORKFILE_H

#include <string>
#include <iostream>
#include "Algorithm.h"

using std::cout;
using std::endl;
using std::string;

template<class T>
class NetworkFile : public Algorithm<T>{

    private:
        // network_file holds the file path of the network data file
        T network_file;

        // trivial_file holds the file path of the Trivial output file
        T trivial_file;

        // bellman_ford_file holds the file path of the Bellman-Ford output file
        T bellman_ford_file;

        // floyd_warshall_file holds the file path of the Floyd-Warshall output file
        T floyd_warshall_file;

    public:
        // Default constructor
        NetworkFile();

        // Constructor that declares input file (w/ path)
        explicit NetworkFile(T);

        // Constructor that declares input file and 3 output files (w/ path)
        explicit NetworkFile(T,T,T,T);

        // Copy constructor
        NetworkFile(const NetworkFile<T>&);

        // Returns file path according to current location
        T get_Network_file();
        T get_Trivial_file();
        T get_Bellman_Ford_file();
        T get_Floyd_Warshall_file();

        // Prints each filepath + filename
        void print();
        ~NetworkFile();
};

// Default Constructor
template<class T>
NetworkFile<T>::NetworkFile()= default;

// Constructor - Uses base initializer to declare add the appropriate path for the network file
template<class T>
NetworkFile<T>::NetworkFile(T network) : network_file("InputFiles/" + network){
}

// Constructor - Uses base initializers to declare and add the appropriate path for input and output file/s
template<class T>
NetworkFile<T>::NetworkFile(T network, T trivial, T bellman_ford,T floyd_warshall) :
    network_file("InputFiles/" + network),
    trivial_file("OutputFiles/" + trivial),
    bellman_ford_file("OutputFiles/" + bellman_ford),
    floyd_warshall_file("OutputFiles/" + floyd_warshall){}

// Copy Constructor w/ base initializers
template<class T>
NetworkFile<T>::NetworkFile(const NetworkFile<T>& originalFiles) :
    network_file(originalFiles.get_Network_file()),
    trivial_file(originalFiles.get_Trivial_file()),
    bellman_ford_file(originalFiles.get_Bellman_Ford_file()),
    floyd_warshall_file(originalFiles.get_Floyd_Warshall_file()){
    this->network_file = originalFiles.get_Network_file();
            this->trivial_file = originalFiles.get_Trivial_file();
            this->bellman_ford_file = originalFiles.get_Bellman_Ford_file();
            this->floyd_warshall_file = originalFiles.get_Floyd_Warshall_file();
    }

// Returns name of input file containing all network data
template<class T>
T NetworkFile<T>::get_Network_file() {
    return this->network_file;
}

// Returns name of Trivial output file
template<class T>
T NetworkFile<T>::get_Trivial_file(){
    return this->trivial_file;
}

// Returns name of Bellman-Ford output file
template<class T>
T NetworkFile<T>::get_Bellman_Ford_file(){
    return this->bellman_ford_file;
}

// Returns name of Floyd-Warshall output file
template<class T>
T NetworkFile<T>::get_Floyd_Warshall_file(){
    return this->floyd_warshall_file;
}

// Prints the location of each of the files defined within the object
template<class T>
void NetworkFile<T>::print(){
    cout << "--------------------------------------------------------------" << endl;
    cout << get_Network_file() << endl;
    cout << get_Trivial_file() << endl;
    cout << get_Bellman_Ford_file() << endl;
    cout << get_Floyd_Warshall_file() << endl;
}

template<class T>
NetworkFile<T>::~NetworkFile<T>() {
    //cout << "Deallocating NetworkFile<T>" << endl;
}

#endif //ALGORITHMS_NETWORKFILE_H
