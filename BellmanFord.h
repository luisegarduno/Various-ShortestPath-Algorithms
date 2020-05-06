//
// Created by luise on 5/6/2020.
//

#ifndef ALGORITHMS_BELLMANFORD_H
#define ALGORITHMS_BELLMANFORD_H

#include <iostream>
#include <string>
#include "Algorithm.h"

using std::string;

template<class V>
class BellmanFord {
    public:
        BellmanFord();
        BellmanFord(Graph<Vertex>, int, int);

    private:
};

template<class V>
BellmanFord<V>::BellmanFord() = default;

template <class V>
BellmanFord<V>::BellmanFord(Graph<Vertex> thisGraph, int source, int N){
    cout << "her" << endl;
}

#endif //ALGORITHMS_BELLMANFORD_H
