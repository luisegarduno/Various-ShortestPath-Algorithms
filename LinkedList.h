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

        void append(T);

        T& getAt(int);
        int getListSize();
        void resetIterator();

        void setLinkedList_head(Node<T>*);
        void setLinkedList_tail(Node<T>*);
        void setLinkedList_iterator(Node<T>*);

        Node<T> * getLinkedList_head();
        Node<T> * getLinkedList_tail();
        Node<T> * getLinkedList_iterator();

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

/**
 * @brief Add item to LinkedList
 *
 * @tparam T class type
 * @param T item to append to LinkedList
 */
template<class T>
void LinkedList<T>::append(T x) {
    Node<T> * newNode = new Node<T>(x);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->setNextNode(newNode);
        newNode->setPreviousNode(tail);
        tail = newNode;
    }
    size++;
}

/**
 * @brief Return data at given index
 *
 * @tparam T class type
 *
 */
template<class T>
T& LinkedList<T>::getAt(int index){
     if(head == nullptr){
         return *(head->getData());
     }
     else if(index == 0){
         return *(head->getData());
     }
     else if(index == size-1){
         return *(tail->getData());
     }
     else{
         Node<T>* counter = head;
         for(int i = 0; i < index; i++){
             counter = counter->getNextNode();
         }
         return *(counter->getData());
     }
 }

/**
 * @brief Total number of nodes in LinkedList
 *
 * @tparam T class type
 * @return size {int} count of nodes in LinkedList
 */
template<class T>
int LinkedList<T>::getListSize() {
    return size;
}

/**
 * @brief Reset iterator to point to head
 *
 * @tparam T class type
 */
template<class T>
void LinkedList<T>::resetIterator() {
    iterator = head;
}

/**
 * @brief Assign the head node to LinkedList
 *
 * @tparam T class type
 * @param node Node<T>*, pointer to node that'll be assigned as head node
 */
template<class T>
void LinkedList<T>::setLinkedList_head(Node<T>* newHead){
    // If head is empty -> set head node
    if(head == nullptr){
        head = newHead;
    }
}

/**
 * @brief Assign the tail node to LinkedList
 *
 * @tparam T class type
 * @param node Node<T>*, pointer to node that'll be assigned as tail node
 */
template<class T>
void LinkedList<T>::setLinkedList_tail(Node<T>* newTail){
    if(tail == nullptr){
        tail = newTail;
    }
}

/**
 * @brief Assign the iterator node to LinkedList
 *
 * @tparam T class type
 * @param node Node<T>*, pointer to node that'll be assigned as iterator node
 */
template<class T>
void LinkedList<T>::setLinkedList_iterator(Node<T>* newIterator){
    iterator = newIterator;
}

/**
 * @brief Return the Head Node in LinkedList
 *
 * @tparam T class type
 * @return Node<T>* pointer to head node
 */
template<class T>
Node<T> * LinkedList<T>::getLinkedList_head(){
    return this->head;
}

/**
 * @brief Return the Tail Node in LinkedList
 *
 * @tparam T class type
 * @return Node<T>* pointer to tail node
 */
template<class T>
Node<T> * LinkedList<T>::getLinkedList_tail(){
    return this->tail;
}

/**
 * @brief Return the Iterator Node in LinkedList
 *
 * @tparam T class type
 * @return Node<T>* pointer to iterator node
 */
template<class T>
Node<T> * LinkedList<T>::getLinkedList_iterator(){
    return this->iterator;
}

/**
 * @brief Default destructor
 *
 * @tparam T class type
 */
template<class T>
LinkedList<T>::~LinkedList<T>(){
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* next = current->getNextNode();
        delete current;
        current = next;
    }
};


#endif //SHORTESTPATH_LINKEDLIST_H
