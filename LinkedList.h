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

    private:
        Node<T> * head;
        Node<T> * tail;
        Node<T> * iterator;

        // '{}' sets default value to 0
        int size{};

        void remove(Node<T>*);

    public:
        // ---- Constructors ----
        LinkedList();

        void append(T);
        void clear();

        T& getAt(int);
        int getListSize();
        void resetIterator();


        // ---- Setters & Getters ----

        void setLinkedList_head(Node<T>*);
        Node<T> * getLinkedList_head();

        void setLinkedList_tail(Node<T>*);
        Node<T> * getLinkedList_tail();

        void setLinkedList_iterator(Node<T>*);
        Node<T> * getLinkedList_iterator();


        // ---- Destructor ----

        ~LinkedList();
};

/**
 * @brief Default constructor
 *
 * @tparam T class type
 */
template<class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), iterator(nullptr){
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
 * @brief Clears the LinkedList
 *
 * @tparam T class type
 */
template<class T>
void LinkedList<T>::clear(){
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* next = current->getNextNode();
        delete current;
        current = next;
    }
}

/**
 * @brief Return data at given index
 *
 * @tparam T class type
 * @param x index of node (int)
 *
 */
template<class T>
T& LinkedList<T>::getAt(int x){
    // Case 1: If head is empty
    // Case 2: Return head if parameter x is 0
    // Case 3: Return tail if parameter x is size-1
    // Case 4: Return data at index x if x is between 0 and size-1
     if(head == nullptr){
         return *(head->getData());
     }
     else if(x == 0){
         return *(head->getData());
     }
     else if(x == size-1){
         return *(tail->getData());
     }
     else{
         Node<T>* counter = head;
         for(int i = 0; i < x; i++){
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
        tail = newHead;
        iterator = newHead;

        size++;
    }
    else{
        // If head is not empty -> set head node and set next node to previous head node
        newHead->setNextNode(head);
        head = newHead;

        size++;
    }
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
 * @brief Assign the tail node to LinkedList
 *
 * @tparam T class type
 * @param node Node<T>*, pointer to node that'll be assigned as tail node
 */
template<class T>
void LinkedList<T>::setLinkedList_tail(Node<T>* newTail){
    if(tail == nullptr){
        head = newTail;
        tail = newTail;
        iterator = newTail;

        size++;
    }
    else{
        tail->setNextNode(newTail);
        newTail->setPreviousNode(tail);
        tail = newTail;
    }
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
 * @brief Assign the iterator node to LinkedList
 *
 * @tparam T class type
 * @param node Node<T>*, pointer to node that'll be assigned as iterator node
 */
template<class T>
void LinkedList<T>::setLinkedList_iterator(Node<T>* newIterator){
    if(iterator == nullptr){
        head = newIterator;
        tail = newIterator;
        iterator = newIterator;

        size++;
    }
    else{
        iterator->setNextNode(newIterator);
        newIterator->setPreviousNode(iterator);
    }
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
    clear();
};


#endif //SHORTESTPATH_LINKEDLIST_H
