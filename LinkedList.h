//
// Created by Luis G. on 8/24/24.
//

#ifndef SHORTESTPATH_LINKEDLIST_H
#define SHORTESTPATH_LINKEDLIST_H

#include "Node.h"
#include <iomanip>
#include <fstream>
#include <climits>
#include <iostream>

using std::cout;
using std::endl;
using std::fstream;

template<class T>
class LinkedList {

    Node<T> * head;
    Node<T> * tail;
    Node<T> * iterator;

    int size;

    private:
        void remove(Node<T>*);

    public:
        LinkedList();

        ~LinkedList();

};

/**
 * @brief Default constructor
 *
 * @tparam T class type
 */
template<class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), iterator(nullptr), size(0){
}

template<class T>
LinkedList<T>::~LinkedList<T>() = default;



#endif //SHORTESTPATH_LINKEDLIST_H
