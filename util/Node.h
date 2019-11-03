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

    virtual ~Node() {
        if (value != nullptr) delete(value);
        delete (next);
    };
    Node(Node* b, Node* a, T v) : prev(b), next(a), value(v) {};
    Node(Node* b, T v) : Node(b, nullptr, v) {};
    Node(T v) : Node(nullptr, v) {};
    Node() = default;

    Node<T>* operator+(int i){
        if (i == 0) return this;
        if (i < 0) return this - (-i);
        if (next == nullptr) return nullptr;
        return next + (i - 1);
    };
    Node<T>* operator-(int i){
        if (i == 0) return this;
        if (i < 0) return this + (-i);
        if (prev == nullptr) return nullptr;
        return prev - (i - 1);
    };
    bool operator==(const Node& n){
        return next == n.next && prev == n.prev && value == n.value;
    };
};


#endif //BASICPYTHONINTERPRETER_NODE_H
