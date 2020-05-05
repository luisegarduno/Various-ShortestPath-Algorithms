//
// Created by luise on 5/5/2020.
//

#ifndef ALGORITHMS_ALGORITHM_H
#define ALGORITHMS_ALGORITHM_H

#include <iostream>

template<class U>
class Algorithm {
    private:
        // network_file holds the file path of the network data file
        U network_file;

        // trivial_file holds the file path of the Trivial output file
        U trivial_file;

        // bellman_ford_file holds the file path of the Bellman-Ford output file
        U bellman_ford_file;

        // floyd_warshall_file holds the file path of the Floyd-Warshall output file
        U floyd_warshall_file;

    public:
        Algorithm();

        //explicit Algorithm(NetworkFile<U>&);
        void compute();


        virtual U get_Network_file() = 0;
        virtual U get_Trivial_file() = 0;
        virtual U get_Bellman_Ford_file() = 0;
        virtual U get_Floyd_Warshall_file() = 0;

        virtual void print() = 0;
        virtual ~Algorithm();

};

template<class U>
Algorithm<U>::Algorithm()= default;

template<class U>
void Algorithm<U>::compute(){

    network_file = get_Network_file();
    trivial_file = get_Trivial_file();
    bellman_ford_file = get_Bellman_Ford_file();
    floyd_warshall_file = get_Floyd_Warshall_file();


    cout << "-----------------------------------------" << endl;
    cout << "filename       -----> " << network_file << endl;
    cout << "Trivial        -----> " << trivial_file << endl;
    cout << "Bellman-Ford   -----> " << bellman_ford_file << endl;
    cout << "Floyd-Warshall -----> " << floyd_warshall_file << endl;
}

template<class U>
Algorithm<U>::~Algorithm<U>() {
    //cout << "Deallocating Algorithm<U>" << endl;
}


#endif //ALGORITHMS_ALGORITHM_H
