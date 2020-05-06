//
// Created by luise on 5/6/2020.
//

#ifndef ALGORITHMS_FLOYDWARSHALL_H
#define ALGORITHMS_FLOYDWARSHALL_H

#include <iostream>
#include <string>

#include <queue>
#include <stack>
#include <vector>
#include "Graph.h"
#include <utility>
#include <climits>
#include <unordered_map>

using std::stack;
using std::pair;
using std::string;
using std::vector;
using std::greater;
using std::to_string;
using std::unordered_map;
using std::priority_queue;
using map_Vertex = unordered_map<string,int>;
using map_Edges = pair<map_Vertex,map_Vertex>;

template<class W>
class FloydWarshall {
public:
    FloydWarshall();
    explicit FloydWarshall(W);
    void findShortestPath(Graph<Vertex>&, int, int);
    void writeToFile(vector<int> const &, int);

    string getVectorValues(map_Vertex, int);

private:
    fstream fout;

    // floyd_warshall_file holds the file path of the Bellman-Ford output file
    W floyd_warshall_file;
};

template<class W>
FloydWarshall<W>::FloydWarshall()= default;

template<class W>
FloydWarshall<W>::FloydWarshall(W outputFile){
    this->floyd_warshall_file = outputFile;

}

template<class W>
void FloydWarshall<W>::findShortestPath(Graph<Vertex>& thisGraph, int sourceNode, int numOfNodes){
    map_Vertex vertex_values;
    auto children_original = thisGraph.getAllNodes(to_string(sourceNode));
    for(int i = 0; i <= thisGraph.graphSize(); i++){
        vertex_values[to_string(i)] = 0;
    }

    int i = 0;
    priority_queue <int, vector<int>, greater<>> magic_nodes;
    children_original.setLinkedList_iterator(children_original.getLinkedList_head());

    vertex_values[to_string(sourceNode)] = i;
    magic_nodes.emplace(i++);

    vector<int> distance (numOfNodes, INT_MAX);
    distance[sourceNode] = 0;

    vector<int> parent (numOfNodes, -1);

    int vertexA, vertexB, edge_weight, k = numOfNodes;

    // Relaxation step (run V-1 times)
    while (--k) {
        while(!magic_nodes.empty()){
            auto children_iterator = thisGraph.getAllNodes(getVectorValues(vertex_values,magic_nodes.top()));
            children_iterator.setLinkedList_iterator(children_iterator.getLinkedList_head());
            int n = children_iterator.getListSize();
            magic_nodes.pop();

            for(int it = 1; it <= n; it++){
                // edge from vertexA to vertexB having weight edge_weight
                vertexA = stoi(children_iterator.getIterator().getVertexNode_A());
                vertexB = stoi(children_iterator.getIterator().getVertexNode_B());
                edge_weight = children_iterator.getIterator().getWeight();

                // if the distance to the destination vertexB can be shortened by taking the edge vertexA to vertexB
                if (distance[vertexA] != INT_MAX && distance[vertexA] + edge_weight < distance[vertexB]){
                    // update distance to the new lower value
                    distance[vertexB] = distance[vertexA] + edge_weight;

                    // set vertexB's parent as vertexA
                    parent[vertexB] = vertexA;
                }

                if(vertex_values[children_iterator.getIterator().getVertexNode_B()] == 0){
                    vertex_values[children_iterator.getIterator().getVertexNode_B()] = i++;
                    magic_nodes.emplace(vertex_values[children_iterator.getIterator().getVertexNode_B()]);
                }
                children_iterator.iterateForward();
            }
        }
    }

    vertex_values.clear();

    for(int j = 0; j <= thisGraph.graphSize(); j++){
        vertex_values[to_string(j)] = 0;
    }

    int j = 1;

    vertex_values[to_string(sourceNode)] = j;
    magic_nodes.emplace(j++);

    while(!magic_nodes.empty()){
        auto children_iterator = thisGraph.getAllNodes(getVectorValues(vertex_values,magic_nodes.top()));
        children_iterator.setLinkedList_iterator(children_iterator.getLinkedList_head());
        int n = children_iterator.getListSize();
        magic_nodes.pop();


        for(int it = 1; it <= n; it++){

            // edge from vertexA, vertexB, weight
            vertexA = stoi(children_iterator.getIterator().getVertexNode_A());
            vertexB = stoi(children_iterator.getIterator().getVertexNode_B());
            edge_weight = children_iterator.getIterator().getWeight();

            // if the distance to the destination u can be shortened by taking the edge vertexA -> vertexB
            if (distance[vertexA] != INT_MAX && distance[vertexA] + edge_weight < distance[vertexB]){
                //cout << distance[vertexA] << " != " <<  INT_MAX << " && " << distance[vertexA] << " + " << edge_weight << " < " << distance[vertexB] << endl;
                //cout << "Negative Weight Cycle" << endl;
                //return;
            }

            if(vertex_values[children_iterator.getIterator().getVertexNode_B()] == 0){
                vertex_values[children_iterator.getIterator().getVertexNode_B()] = j++;
                magic_nodes.emplace(vertex_values[children_iterator.getIterator().getVertexNode_B()]);
            }
            children_iterator.iterateForward();
        }
    }

    fout.open(floyd_warshall_file.c_str(), std::ios::app);
    if(!fout.is_open()){
        cout << "'" << floyd_warshall_file << "' could not be opened. Please check input files." << endl;
        exit(-1);
    }

    for (int s = 1; s < numOfNodes; s++){
        fout << "Total Distance   " ;
        fout << "[" << sourceNode << "] : ";
        fout << std::setw(5) << std::left << "[" + to_string(s) + "]";
        fout << std::setw(6) << std::right << "  -->  " <<  std::setw(7) << std::left << distance[s];
        fout << std::setw(30) << std::right <<  "Shortest Path : [ ";
        writeToFile(parent, s);
        fout << "]" << '\n';
    }
    fout.close();
    fout.clear();

}


template<class W>
string FloydWarshall<W>::getVectorValues(map_Vertex tempVector, int here){
    for(auto start = 1; start <= tempVector.size(); start++){
        if(tempVector[to_string(start)] == here){
            return to_string(start);
        }
    }
    return "";
}

template <class W>
void FloydWarshall<W>::writeToFile(vector<int> const & sourceVertex, int currentVertex){
    if(currentVertex < 0){
        return;
    }

    writeToFile(sourceVertex, sourceVertex[currentVertex]);
    fout << currentVertex << " ";
}

#endif //ALGORITHMS_FLOYDWARSHALL_H
