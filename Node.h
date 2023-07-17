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

// Default constructor
template<class T>
Node<T>::Node() : next(nullptr), previous(nullptr){
}

// Constructor - with data value passed in as paramater
template<class T>
Node<T>::Node(T dataValue) : next(nullptr), previous(nullptr), data(dataValue){
}

// Constructor - with Node passed in as paramater - only fetch data value
template<class T>
Node<T>::Node(const Node<T>& node) : data(node.data), next(nullptr), previous(nullptr){
}

// Constructor - with Node data, next node ptr, &  previous node ptr passed in
template<class T>
Node<T>::Node(const Node<T>& node, Node<T>* nextNode, Node<T>* previousNode)
  : data(node.data), next(nextNode), previous(previousNode){
}

// Setter for Data
template<class T>
void Node<T>::setData(T* data){
  this->data = data;
}

// Setter for next node
template<class T>
void Node<T>::setNextNode(Node<T>* setNext){
  this->next = setNext;
}

// Setter for previous node
template<class T>
void Node<T>::setPreviousNode(Node<T>* setPrevious){
  this->previous = setPrevious;
}

// Getter for node data 
template<class T>
T* Node<T>::getData(){
  return &data;
}

// Getter for next node
template<class T>
Node<T>* Node::getNextNode(){
  return this->next;
}

// Getter for previous node
template<class T>
Node<T>* Node<T>::getPreviousNode(){
  return this->previous;
}

// Destructor
template<class T>
Node<T>::~Node<T>() = default;

#endif // SHORTESTPATH_NODE_H
