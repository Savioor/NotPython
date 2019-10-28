//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_NODE_H
#define BASICPYTHONINTERPRETER_NODE_H

template <class T>
class Node {

public:
    Node* next;
    Node* prev;
    T value;

    virtual ~Node();
    Node(Node*, Node*, T);
    Node(Node*, T);
    Node(T);
    Node();

    Node<T> * operator+(int);
    Node<T> * operator-(int);
    bool operator==(const Node&);
};


#endif //BASICPYTHONINTERPRETER_NODE_H
