//
// Created by luise on 5/5/2020.
//

#ifndef ALGORITHMS_ALGORITHM_H
#define ALGORITHMS_ALGORITHM_H

#include <map>
#include <string>
#include "Graph.h"
#include <fstream>
#include <cstring>
#include "Vertex.h"
#include "FileReader.h"
#include "BellmanFord.h"
#include <bits/stdc++.h>
#include <unordered_map>


using std::ios;
using std::map;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ofstream;
using std::to_string;
using std::unordered_map;
using map_Vertex = unordered_map<string,int>;
using map_Edges = pair<map_Vertex,map_Vertex>;

template<class U>
class Algorithm {
    private:
        ifstream fin;                   // Reads in from inputFile;
        ofstream fout;                  // Outputs to outputFile;
        Graph<Vertex> networks;

        // network_file holds the file path of the network data file
        U network_file;

        // trivial_file holds the file path of the Trivial output file
        U trivial_file;

        // bellman_ford_file holds the file path of the Bellman-Ford output file
        U bellman_ford_file;

        // floyd_warshall_file holds the file path of the Floyd-Warshall output file
        U floyd_warshall_file;

    public:
        // Default Constructor
        Algorithm();

        void readNetworkFile(U);

        // Used as constructor
        void setFileName(string);

        //explicit Algorithm(NetworkFile<U>&);
        void compute();

        // Set functions to virtual so they use polymorphism with the NetworkFile
        virtual U get_Network_file() = 0;
        virtual U get_Trivial_file() = 0;
        virtual U get_Bellman_Ford_file() = 0;
        virtual U get_Floyd_Warshall_file() = 0;

        // Set Destructor to deallocate memory from perhaps the NetworkFile
        virtual ~Algorithm();
};


// Default constructor
template<class U>
Algorithm<U>::Algorithm()= default;

// Used to initialize the Algorithm process
template<class U>
void Algorithm<U>::compute(){
    network_file = get_Network_file();
    trivial_file = get_Trivial_file();
    bellman_ford_file = get_Bellman_Ford_file();
    floyd_warshall_file = get_Floyd_Warshall_file();

    readNetworkFile(network_file);
}

template<class U>
void Algorithm<U>::readNetworkFile(U networkFile) {
    //Graph<Vertex> graph;
    map_Vertex vertexOrder;
    vector<string> listOfVertex;

    string vertexNode;
    char startBracket, endBracket;
    int totalNumberOfVertex, totalNumberOfEdges, vertexNode_A, vertexNode_B, weight, edgeCounter = 0;

    setFileName(networkFile);

    fin >> startBracket >> totalNumberOfVertex >> endBracket;
    fin >> startBracket >> totalNumberOfEdges  >> endBracket;

    // Create edges starting from 1 and add them to listOfVertex
    for (int vertexMap = 1; vertexMap <= totalNumberOfVertex; vertexMap++) {
        vertexNode = to_string(vertexMap);
        listOfVertex.push_back(vertexNode);
    }


    for (int i = 1; i <= totalNumberOfEdges; i++) {
        fin >> vertexNode_A >> vertexNode_B >> weight;

        Vertex newVertexNode(to_string(vertexNode_A), to_string(vertexNode_B), weight, false);
        networks.add(newVertexNode);

        Vertex newReversedVertexNode(to_string(vertexNode_B), to_string(vertexNode_A), weight, false);
        networks.add(newReversedVertexNode);
    }

    //networks.printMatrix();
    fin.close();

    int tempStart = 1;
    auto * newAlgorithm = new BellmanFord<string>(get_Bellman_Ford_file());
    newAlgorithm->findShortestPath(networks, tempStart, totalNumberOfVertex + 1);
    delete newAlgorithm;

}


// setFileName sets the given file name in the inputFile, as well as checking if it is the
// correct format type.
template<class U>
void Algorithm<U>::setFileName(string networkFile){
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
        fin.open(backupnetworkFile.c_str());
        if(!fin.is_open()){
            cout << "'" << networkFile << "' or '" << backupnetworkFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
        networkFile = backupnetworkFile;
    }
    else{
        fin.open(networkFile.c_str());
        if(!fin.is_open()){
            cout << "'" << networkFile << "' could not be opened. Please check command line." << endl;
            exit(-1);
        }
    }

}



// Default destructor
template<class U>
Algorithm<U>::~Algorithm()= default;
    //cout << "Deallocating Algorithm<U>" << endl;



#endif //ALGORITHMS_ALGORITHM_H
