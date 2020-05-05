//
// Created by luise on 5/5/2020.
//

#ifndef ALGORITHMS_NETWORKFILE_H
#define ALGORITHMS_NETWORKFILE_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;


template<class T>
class NetworkFile {

    private:
        T network_file;
        T trivial_file;
        T bellman_ford_file;
        T floyd_warshall_file;


    public:
        NetworkFile();
        explicit NetworkFile(T);
        NetworkFile(T,T,T,T);
        NetworkFile(const NetworkFile<T>&);


        void set_Trivial_file(T);
        void set_Bellman_Ford_file(T);
        void set_Floyd_Warshall_file(T);

        void set_Output_files(T,T,T);

        T get_Network_file();
        T get_Trivial_file();
        T get_Bellman_Ford_file();
        T get_Floyd_Warshall_file();

        T print();
};
template<class T>
NetworkFile<T>::NetworkFile()= default;

template<class T>
NetworkFile<T>::NetworkFile(T network) : network_file(network){
}

template<class T>
NetworkFile<T>::NetworkFile(T network,T trivial,T bellman_ford,T floyd_warshall) :
    network_file(network), trivial_file(trivial), bellman_ford_file(bellman_ford), floyd_warshall_file(floyd_warshall){
}

template<class T>
NetworkFile<T>::NetworkFile(const NetworkFile<T>& originalFiles) :
    network_file(originalFiles.get_Network_file()), trivial_file(originalFiles.get_Trivial_file()),
    bellman_ford_file(originalFiles.get_Bellman_Ford_file()), floyd_warshall_file(originalFiles.get_Floyd_Warshall_file())
{}

template<class T>
void NetworkFile<T>::set_Output_files(T t_file, T bf_file, T fw_file){
    this->trivial_file = t_file;
    this->bellman_ford_file = bf_file;
    this->floyd_warshall_file = fw_file;
}

template<class T>
void NetworkFile<T>::set_Trivial_file(T filename){
    this->trivial_file = filename;
}

template<class T>
void NetworkFile<T>::set_Bellman_Ford_file(T filename){
    this->bellman_ford_file = filename;
}

template<class T>
void NetworkFile<T>::set_Floyd_Warshall_file(T filename){
    this->floyd_warshall_file = filename;
}

template<class T>
T NetworkFile<T>::get_Network_file(){
    return this->network_file;
}

template<class T>
T NetworkFile<T>::get_Trivial_file(){
    return this->trivial_file;
}

template<class T>
T NetworkFile<T>::get_Bellman_Ford_file(){
    return this->bellman_ford_file;
}

template<class T>
T NetworkFile<T>::get_Floyd_Warshall_file(){
    return this->floyd_warshall_file;
}

template<class T>
T NetworkFile<T>::print(){
    cout << "InputFiles/" << get_Network_file() << endl;
    cout << "OutputFiles/" << get_Trivial_file() << endl;
    cout << "OutputFiles/" << get_Bellman_Ford_file() << endl;
    cout << "OutputFiles/" << get_Floyd_Warshall_file() << endl;
}

#endif //ALGORITHMS_NETWORKFILE_H
