//
// Created by luise on 5/3/2020.
//

#include "Edge.h"
#include <utility>

Edge::Edge() : vertexA(""), vertexB(""), weight(0), visitedFlag(false){
}

Edge::Edge(string newVertex) : vertexA(move(newVertex)), vertexB(""), weight(0), visitedFlag(false){
}

Edge::Edge(string nodeA, string nodeB, int weight, bool hasVisited) : vertexA(move(nodeA)) , vertexB(move(nodeB)){
    this->weight = weight;
    this->visitedFlag = hasVisited;
}

Edge::Edge(const Edge& originalVertex){
    *this = originalVertex;
}

Edge* Edge::operator=(const Edge* originalVertex){
    setVertexNode_A(originalVertex->vertexA);
    setVertexNode_B(originalVertex->vertexB);
    setWeight(originalVertex->weight);
    setVisitedFlag(originalVertex->visitedFlag);
    return this;
}

Edge& Edge::operator=(const Edge& originalVertex){
    setVertexNode_A(originalVertex.vertexA);
    setVertexNode_B(originalVertex.vertexB);
    setWeight(originalVertex.weight);
    setVisitedFlag(originalVertex.visitedFlag);
    return *this;
}

void Edge::setVertexNode_A(string newVertexA){
    this->vertexA = move(newVertexA);
}

void Edge::setVertexNode_B(string newVertexB){
    this->vertexB = move(newVertexB);
}

void Edge::setWeight(int newWeight){
    this->weight = newWeight;
}

void Edge::setVisitedFlag(bool newVisitedFlag){
    this->visitedFlag = newVisitedFlag;
}

string Edge::getVertexNode_A(){
    return vertexA;
}

string Edge::getVertexNode_B(){
    return vertexB;
}

int Edge::getWeight(){
    return weight;
}

bool Edge::getVisitedFlag(){
    return visitedFlag;
}

void Edge::addVertex(string newVertex){
    vertices.push_back(newVertex);
}
