//
// Created by alexey on 28/10/2019.
//

#include <armadillo_bits/newarp_SortEigenvalue.hpp>
#include "LinkedList.h"

template<class T>
int LinkedList<T>::size() {
    if (startNode == nullptr){
        return 0
    }
    int count = 1;
    Node<T>* counter = startNode;
    while(counter != endNode){
        count++;
        counter = counter + 1;
    }
    return count;
}

template<class T>
Node<T> *LinkedList<T>::at(int i) {
    return startNode + i;
}

template<class T>
T LinkedList<T>::valueAt(int i) {
    return (startNode + i)->value;
}

template<class T>
void LinkedList<T>::disconnect(int i) {
    disconnect(at(i));
}


template<class T>
void LinkedList<T>::disconnect(Node<T> *n) {
    disconnectAndKeepAlive(n);
    delete n;
}

template<class T>
void LinkedList<T>::disconnectAndKeepAlive(Node<T> *n) {
    Node<T>* bef = n->prev;
    Node<T>* aft = n->next;
    bef->next = aft;
    aft->prev = bef;
}

template<class T>
void LinkedList<T>::connectAfter(Node<T> *n, Node<T> &node) {
    Node<T>* twoAfter = node + 1;
    node.next = n;
    n->prev = node;
    n->next = twoAfter;
    if (twoAfter != nullptr) twoAfter->prev = n;
    else endNode = n;
}

template<class T>
void LinkedList<T>::connectBefore(Node<T> *n, Node<T> &node) {
    Node<T>* twoBefore = node - 1;
    if (twoBefore != nullptr) twoBefore->next = n;
    else startNode = n;
    n->prev = twoBefore;
    n->next = node;
    node.prev = n;
}

template<class T>
void LinkedList<T>::disconnectAndKeepAlive(int i) {
    disconnectAndKeepAlive(at(i));
}

template<class T>
void LinkedList<T>::connectAfter(int i, Node<T> &node) {
    connectAfter(at(i), node);
}

template<class T>
void LinkedList<T>::connectBefore(int i, Node<T> &node) {
    connectBefore(at(i), node);
}

template<class T>
LinkedList<T>::~LinkedList() {
    delete startNode;
}
