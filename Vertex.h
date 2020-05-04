//
// Created by luise on 5/3/2020.
//

#ifndef ALGORITHMS_VERTEX_H
#define ALGORITHMS_VERTEX_H


#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::move;
using std::string;

class Vertex {
    private:
        string vertex;
        string predecessor;
        int weight{};
        bool visitedFlag{};

    public:
        Vertex();

        Vertex(string);

        Vertex(string, string, int, bool);

        Vertex(const Vertex &);

        Vertex &operator=(const Vertex &);

        Vertex *operator=(const Vertex *);

        void setVertexNode(string);
        void setPredecessorNode(string);
        void setWeight(int);
        void setVisitedFlag(bool);

        string getVertexNode();
        string getPredecessorNode();
        int getWeightNode();
        bool getVisitedFlag();
};


#endif //ALGORITHMS_VERTEX_H
