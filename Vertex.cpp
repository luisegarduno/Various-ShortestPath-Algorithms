//
// Created by Luis G. on 8/31/24.
//

#include "Vertex.h"

/**
 * @brief Default constructor
 */
Vertex::Vertex() : vertex(""), predecessor(""){
}

/**
 * @brief Constructor
 *
 * @param newVertex vertex value
 */
Vertex::Vertex(string newVertex) : vertex(std::move(newVertex)), predecessor(""){
}

Vertex::Vertex(string node1, string node2, int between, bool hasVisited) {
    this->vertex = std::move(node1);
    this->predecessor = std::move(node2);
    this->betweeness = between;
    this->visited = hasVisited;
}

/**
 * @brief Copy constructor for Vertex class
 *
 * @param originalVertex Vertex to copy from
 */
Vertex::Vertex(const Vertex& originalVertex){
    *this = originalVertex;
}

/**
 * @brief Copy constructor by reference for Vertex class
 *
 * @param originalVertex reference to Vertex to copy from
 */
Vertex& Vertex::operator=(const Vertex& originalVertex){
    setVertex(originalVertex.vertex);
    setPredecessor(originalVertex.predecessor);
    setBetweeness(originalVertex.betweeness);
    setVisited(originalVertex.visited);

    return *this;
}


/**
 * @brief Copy constructor by pointer for Vertex class
 *
 * @param originalVertex piointer to Vertex to copy from
 */
Vertex* Vertex::operator=(const Vertex* originalVertex){
    setVertex(originalVertex->vertex);
    setPredecessor(originalVertex->predecessor);
    setBetweeness(originalVertex->betweeness);
    setVisited(originalVertex->visited);

    return this;
}

/**
 * @brief Set vertex value
 *
 * @param v vertex value
 */
void Vertex::setVertex(string v){
    this->vertex = std::move(v);
}

/**
 * @brief Get vertex value
 *
 * @return vertex value
 */
string Vertex::getVertex(){
    return vertex;
}

/**
 * @brief Set predecessor
 *
 * @param p predecessor value
 */
void Vertex::setPredecessor(string p){
    this->predecessor = std::move(p);
}

/**
 * @brief Get predecessor
 *
 * @return predecessor
 */
string Vertex::getPredecessor(){
    return predecessor;
}

/**
 * @brief Set betweeness
 *
 * @param b betweeness value
 */
void Vertex::setBetweeness(int b){
    this->betweeness = b;
}

/**
 * @brief Get betweeness
 *
 * @return betweeness value
 */
int Vertex::getBetweeness(){
    return betweeness;
}

/**
 * @brief Set boolean value for visited
 *
* @param vs visited boolean value
 */
void Vertex::setVisited(bool vs){
    this->visited = vs;
};

/**
 * @brief Return whether the vertex has been visited
 *
 * @param vertex value
 */
bool Vertex::getVisited(){
    return visited;
}

/**
 * @brief destructor
 */
Vertex::~Vertex() = default;
