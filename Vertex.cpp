//
// Created by luise on 5/3/2020.
//

#include "Vertex.h"

#include <utility>

Vertex::Vertex() : vertex(""), predecessor(""), weight(0), visitedFlag(false){
}

Vertex::Vertex(string newVertex) : vertex(move(newVertex)), predecessor(""), weight(0), visitedFlag(false){
}

Vertex::Vertex(string node1, string node2, int between, bool hasVisited) : vertex(move(node1)) , predecessor(move(node2)){
    this->weight = between;
    this->visitedFlag = hasVisited;
}

Vertex::Vertex(const Vertex& originalVertex){
    *this = originalVertex;
}

Vertex* Vertex::operator=(const Vertex* originalVertex){
    setVertexNode(originalVertex->vertex);
    setPredecessorNode(originalVertex->predecessor);
    setWeight(originalVertex->weight);
    setVisitedFlag(originalVertex->visitedFlag);
    return this;
}

Vertex& Vertex::operator=(const Vertex& originalVertex){
    setVertexNode(originalVertex.vertex);
    setPredecessorNode(originalVertex.predecessor);
    setWeight(originalVertex.weight);
    setVisitedFlag(originalVertex.visitedFlag);
    return *this;
}

void Vertex::setVertexNode(string newVertex){
    this->vertex = move(newVertex);
}

void Vertex::setPredecessorNode(string newPredecessor){
    this->predecessor = move(newPredecessor);
}

void Vertex::setWeight(int newWeight){
    this->weight = newWeight;
}

void Vertex::setVisitedFlag(bool newVisitedFlag){
    this->visitedFlag = newVisitedFlag;
}

string Vertex::getVertexNode(){
    return vertex;
}

string Vertex::getPredecessorNode(){
    return predecessor;
}

int Vertex::getWeightNode(){
    return weight;
}

bool Vertex::getVisitedFlag(){
    return visitedFlag;
}
