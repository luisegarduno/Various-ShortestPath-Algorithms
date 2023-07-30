//
// Created by Luis G. on 07/17/2023.
//

#ifndef SHORTESTPATH_NODE_H
#define SHORTESTPATH_NODE_H

#include <iostream>

template<class T>
class Node{
    public:
        Node();
        Node(T);
        Node(const Node<T>&);
        Node(const Node<T>&, Node<T>*, Node<T>*);

        void setData(T*);
        void setNextNode(Node<T>*);
        void setPreviousNode(Node<T>*);

        T* getData();
        Node<T>* getNextNode();
        Node<T>* getPreviousNode();

        ~Node();

    private:
        Node<T>* next;
        Node<T>* previous;
        T data;
};

/**
 * Default constructor
 *
 * @tparam T class type
 */
template<class T>
Node<T>::Node() : next(nullptr), previous(nullptr){
}

/**
 * Constructor - with data value passed in as parameter
 *
 * @tparam T class type
 * @param dataValue data value to be stored in node
 */
template<class T>
Node<T>::Node(T dataValue) : next(nullptr), previous(nullptr), data(dataValue){
}

/**
 * Constructor - with Node passed in as parameter - only fetch data value
 *
 * @tparam T class type
 * @param node with node data value to be stored in node
 */
template<class T>
Node<T>::Node(const Node<T>& node) : data(node.data), next(nullptr), previous(nullptr){
}

/**
 * Constructor - with Node passed in as parameter - fetch data value, next node ptr, & previous node ptr
 *
 * @tparam T class type
 * @param node node with data value to be stored in node
 * @param nextNode next node ptr
 * @param previousNode previous node ptr
 */
template<class T>
Node<T>::Node(const Node<T>& node, Node<T>* nextNode, Node<T>* previousNode)
  : data(node.data), next(nextNode), previous(previousNode){
}

/**
 * Setter for data
 *
 * @tparam T class type
 * @param data data value to be stored in node
 */
template<class T>
void Node<T>::setData(T* data){
  this->data = data;
}

/**
 * Setter for next node
 *
 * @tparam T class type
 * @param setNext next node ptr
 */
template<class T>
void Node<T>::setNextNode(Node<T>* setNext){
  this->next = setNext;
}

/**
 * Setter for previous node
 *
 * @tparam T class type
 * @param setPrevious previous node ptr
 */
template<class T>
void Node<T>::setPreviousNode(Node<T>* setPrevious){
  this->previous = setPrevious;
}

/**
 * Getter for node data
 *
 * @tparam T class type
 * @return node data
 */
template<class T>
T* Node<T>::getData(){
  return &data;
}

/**
 * Getter for next node
 *
 * @tparam T class type
 * @return next node ptr
 */
template<class T>
Node<T>* Node<T>::getNextNode(){
  return this->next;
}

/**
 * Getter for previous node
 *
 * @tparam T class type
 * @return previous node ptr
 */
template<class T>
Node<T>* Node<T>::getPreviousNode(){
  return this->previous;
}

/**
 * Destructor
 *
 * @tparam T class type
 */
template<class T>
Node<T>::~Node<T>() = default;

#endif // SHORTESTPATH_NODE_H
