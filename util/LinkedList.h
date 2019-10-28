//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_LINKEDLIST_H
#define BASICPYTHONINTERPRETER_LINKEDLIST_H


#include "Node.h"

template <class T>
class LinkedList {

protected:
    Node<T>* startNode;
    Node<T>* endNode;

public:
    virtual int size();
    virtual Node<T>* at(int i);
    virtual T valueAt(int i);
    virtual void disconnect(int i);
    virtual void disconnectAndKeepAlive(int i);
    virtual void connectAfter(int i, Node<T>& node);
    virtual void connectBefore(int i, Node<T>& node);

    virtual void disconnect(Node<T>* n);
    virtual void disconnectAndKeepAlive(Node<T>* n);
    virtual void connectAfter(Node<T>* n, Node<T>& node);
    virtual void connectBefore(Node<T>* n, Node<T>& node);

    virtual ~LinkedList();
};


#endif //BASICPYTHONINTERPRETER_LINKEDLIST_H
