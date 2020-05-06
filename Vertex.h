//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_VERTEX_H
#define ALGORITHMS_VERTEX_H

#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::move;
using std::pair;
using std::vector;
using std::string;
using VerticePair = pair<string,string>;

class Vertex {
private:
    vector<string> vertices;
    vector< pair< VerticePair, int> > edges;
    string vertexA;
    string vertexB;
    int    weight{};
    bool   visitedFlag{};

public:
    Vertex();
    explicit Vertex(string);
    Vertex(string,string,int,bool);
    Vertex(const Vertex&);
    Vertex& operator=(const Vertex&);
    Vertex* operator=(const Vertex*);

    void setVertexNode_A(string);
    void setVertexNode_B(string);
    void setWeight(int);
    void setVisitedFlag(bool);
    void addVertex(string);

    string getVertexNode_A();
    string getVertexNode_B();
    int    getWeight();
    bool   getVisitedFlag();
};


#endif //ALGORITHMS_VERTEX_H
