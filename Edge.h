//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_EDGE_H
#define ALGORITHMS_EDGE_H


#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::move;
using std::pair;
using std::vector;
using std::string;

class Edge {
    private:
        vector<string> vertices;
        vector< pair< pair<string,string>, int> > edges;
        string vertexA;
        string vertexB;
        int    weight{};
        bool   visitedFlag{};

    public:
        Edge();
        Edge(string);
        Edge(string,string,int,bool);
        Edge(const Edge&);
        Edge& operator=(const Edge&);
        Edge* operator=(const Edge*);

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


#endif //ALGORITHMS_EDGE_H
