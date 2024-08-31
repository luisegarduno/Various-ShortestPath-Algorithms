//
// Created by Luis G. on 8/31/24.
//

#ifndef SHORTESTPATH_VERTEX_H
#define SHORTESTPATH_VERTEX_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
 * ToDo: Create 2 additional classes:
 * 1. Vertex_Undirected
 * 2. Vertex_Directed
 *
 * Would be good to do inheritance here
 */
class Vertex {
    private:
        string vertex;
        string predecessor;
        int betweeness{};
        bool visited{};

    public:
        Vertex();
        explicit Vertex(string);
        Vertex(string, string, int, bool);
        Vertex(const Vertex&);
        Vertex& operator=(const Vertex&);
        Vertex* operator=(const Vertex*);

        // ---- Setters & Getters ----

        void setVertex(string);
        string getVertex();

        void setPredecessor(string);
        string getPredecessor();

        void setBetweeness(int);
        int getBetweeness();

        void setVisited(bool);
        bool getVisited();

        ~Vertex();
};


#endif //SHORTESTPATH_VERTEX_H
