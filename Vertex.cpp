//
// Created by luise on 5/3/2020.
//
#include "Vertex.h"
#include <utility>

Vertex::Vertex() : vertexA(""), vertexB(""), weight(0), visitedFlag(false){
}

Vertex::Vertex(string newVertex) : vertexA(move(newVertex)), vertexB(""), weight(0), visitedFlag(false){
}

Vertex::Vertex(string nodeA, string nodeB, int between, bool hasVisited) : vertexA(move(nodeA)) , vertexB(move(nodeB)){
    this->weight = between;
    this->visitedFlag = hasVisited;
}

Vertex::Vertex(const Vertex& originalVertex){
    *this = originalVertex;
}

Vertex* Vertex::operator=(const Vertex* originalVertex){
    setVertexNode_A(originalVertex->vertexA);
    setVertexNode_B(originalVertex->vertexB);
    setWeight(originalVertex->weight);
    setVisitedFlag(originalVertex->visitedFlag);
    return this;
}

Vertex& Vertex::operator=(const Vertex& originalVertex){
    setVertexNode_A(originalVertex.vertexA);
    setVertexNode_B(originalVertex.vertexB);
    setWeight(originalVertex.weight);
    setVisitedFlag(originalVertex.visitedFlag);
    return *this;
}

void Vertex::setVertexNode_A(string newVertexA){
    this->vertexA = move(newVertexA);
}

void Vertex::setVertexNode_B(string newVertexB){
    this->vertexB = move(newVertexB);
}

void Vertex::setWeight(int newWeight){
    this->weight = newWeight;
}

void Vertex::setVisitedFlag(bool newVisitedFlag){
    this->visitedFlag = newVisitedFlag;
}

string Vertex::getVertexNode_A(){
    return vertexA;
}

string Vertex::getVertexNode_B(){
    return vertexB;
}

int Vertex::getWeight(){
    return weight;
}

bool Vertex::getVisitedFlag(){
    return visitedFlag;
}
