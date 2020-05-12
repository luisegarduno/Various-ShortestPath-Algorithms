//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_GRAPH_H
#define ALGORITHMS_GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <fstream>
#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

template<class T>
class Graph{
    private:
        LinkedList< LinkedList<T> > graph;
        int size = 0;

    public:
        Graph();
        void add(T);
        int graphSize();
        LinkedList<T> getAllNodes(const string&);
        LinkedList<T> &checkListOfVertexNodes(const string &);
        bool checkNetworkConnections(const string&,const string&, const LinkedList<T>&);

        void printGraph();
        void printMatrix();

        void outputGraph_ToFile(const string&);
        void outputMatrix_ToFile(const string&);

};

template <class T>
Graph<T>::Graph() = default;

template<class T>
void Graph<T>::add(T newNode){

    if(newNode.getVertexNode_B() != ""){

        LinkedList<T>* vertexLinkedList = &checkListOfVertexNodes(newNode.getVertexNode_A());

        if(vertexLinkedList != nullptr){

            bool dataExists = checkNetworkConnections(newNode.getVertexNode_A(), newNode.getVertexNode_B(), *vertexLinkedList);

            if(!dataExists){
                vertexLinkedList->append(newNode);                      // adds connection to Node
                size++;
            }
        }

        else{
            LinkedList<T> newLinkedLinkedList;
            newLinkedLinkedList.append(newNode);
            size++;
            graph.append(newLinkedLinkedList);                      // add this LinkedLinkedList to graph
        }
    }
}
template<class T>
int Graph<T>::graphSize(){
    return this->size;
}

template<class T>
LinkedList<T> & Graph<T>::checkListOfVertexNodes(const string &vertexValue) {
    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    while(currentLinkedList != nullptr){
        if(currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() == vertexValue){
            return *(currentLinkedList->getData());
        }
        currentLinkedList = currentLinkedList->getNextNode();
    }

    LinkedList<T> *temp_val = nullptr;
    return *temp_val;
}

template<class T>
bool Graph<T>::checkNetworkConnections(const string& vertex_A, const string& vertex_B, const LinkedList<T>& aNetworkLinkedList){
    auto tempIterator = aNetworkLinkedList;
    tempIterator.resetIterator();

    while(tempIterator.iteratorIsValid()){
        if(tempIterator.getIterator().getVertexNode_A() == vertex_B){
            return true;
        }
        tempIterator.iterateForward();
    }
    return false;
}

template<class T>
LinkedList<T> Graph<T>::getAllNodes(const string& aVertex){

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();
    LinkedList<T> graphVertex = LinkedList<T>();
    currentLinkedList->getData()->resetIterator();

    while(currentLinkedList != nullptr){
        currentLinkedList->getData()->resetIterator();
        while(currentLinkedList->getData()->iteratorIsValid()){
            if(currentLinkedList->getData()->getIterator().getVertexNode_A() == aVertex){
                graphVertex.append(currentLinkedList->getData()->getIterator());
            }
            currentLinkedList->getData()->iterateForward();
        }
        currentLinkedList = currentLinkedList->getNextNode();
    }
    return graphVertex;
}

template<class T>
void Graph<T>::printGraph(){

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    cout << "----------------------------- Format: Vertex (Weight) ------------------------------------" << endl << endl;
    while(currentLinkedList != nullptr){
        cout << currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() << " --> ";
        currentLinkedList->getData()->print();
        currentLinkedList = currentLinkedList->getNextNode();
        if(currentLinkedList != nullptr){
            cout << endl;
        }
    }
    cout << "------------------------------------------------------------------------------------------- " << endl;
}

template<class T>
void Graph<T>::printMatrix(){
    cout << "--> FORMAT : MATRIX" << endl << endl;
    Node< LinkedList<T> >* tempLinkedList = graph.getLinkedList_head();
    int counter = 1;
    cout << "    " << std::setw(3) << std::left << "";
    while(tempLinkedList != nullptr){
        cout << std::setw(4) << std::left << tempLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() ;
        tempLinkedList = tempLinkedList->getNextNode();
        if(tempLinkedList != nullptr){
            counter++;
        }
    }
    cout << endl;


    cout << "------";
    for(int i = 0; i < counter; i++){
        cout << "----";
    }
    cout << endl;

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    while(currentLinkedList != nullptr){
        cout << std::setw(4) << std::left << currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() << "|  ";
        currentLinkedList->getData()->printMatrix(counter);
        currentLinkedList = currentLinkedList->getNextNode();
        if(currentLinkedList != nullptr){
            cout << endl;
        }
    }

    cout << "------";
    for(int i = 0; i < counter; i++){
        cout << "----";
    }
    cout << endl;
}

template<class T>
void Graph<T>::outputGraph_ToFile(const string& outputFile){
    fstream fout;
    fout.open(outputFile.c_str(), std::ios::app);
    if (!fout.is_open()) {
        cout << "'" << outputFile << "' could not be opened. Please check input files." << endl;
        exit(-1);
    }


    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    fout << "\n--> FORMAT : DIRECTED GRAPH" << endl << endl;
    while(currentLinkedList != nullptr){
        fout << currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() << " --> ";
        currentLinkedList->getData()->printGraph_ToFile(fout);
        currentLinkedList = currentLinkedList->getNextNode();
        if(currentLinkedList != nullptr){
            fout << endl;
        }
    }

    fout.close();
    fout.clear();
}

template<class T>
void Graph<T>::outputMatrix_ToFile(const string& outputFile){
    fstream fout;
    fout.open(outputFile.c_str(), std::ios::app);
    if (!fout.is_open()) {
        cout << "'" << outputFile << "' could not be opened. Please check input files." << endl;
        exit(-1);
    }

    fout << "\n--> FORMAT : MATRIX" << endl << endl;
    Node< LinkedList<T> >* tempLinkedList = graph.getLinkedList_head();
    int counter = 1;
    fout << "    " << std::setw(3) << std::left << "";
    while(tempLinkedList != nullptr){
        fout << std::setw(4) << std::left << tempLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A();
        tempLinkedList = tempLinkedList->getNextNode();
        if(tempLinkedList != nullptr){
            counter++;
        }
    }
    fout << endl;


    fout << "------";
    for(int i = 0; i < counter; i++){
        fout << "----";
    }
    fout << endl;

    Node< LinkedList<T> >* currentLinkedList = graph.getLinkedList_head();

    while(currentLinkedList != nullptr){
        fout << std::setw(4) << std::left << currentLinkedList->getData()->getLinkedList_head()->getData()->getVertexNode_A() << "|  ";
        currentLinkedList->getData()->printMatrix_ToFile(fout,counter);
        currentLinkedList = currentLinkedList->getNextNode();
        if(currentLinkedList != nullptr){
            fout << endl;
        }
    }

    fout << "------";
    for(int i = 0; i < counter; i++){
        fout << "----";
    }
    fout << endl;

    fout.close();
    fout.clear();
}


#endif //ALGORITHMS_GRAPH_H
