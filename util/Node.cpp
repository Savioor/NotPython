//
// Created by alexey on 28/10/2019.
//

#include "Node.h"

template<class T>
Node<T>::~Node() {
    delete (next);
}


template<class T>
Node<T>::Node(Node * b, Node * a, T v) : prev(b), next(a), value(v) {

}

template<class T>
Node<T>::Node(Node * b, T v) : Node(b, nullptr, v) {

}

template<class T>
Node<T>::Node(T v ) : Node(nullptr, v) {

}

template<class T>
Node<T>::Node() = default;

template<class T>
Node<T> *Node<T>::operator+(int i) {
    if (i == 0) return this;
    if (i < 0) return this - (-i);
    if (next == nullptr) return nullptr;
    return next + (i - 1);
}

template<class T>
Node<T> *Node<T>::operator-(int i) {
    if (i == 0) return this;
    if (i < 0) return this + (-i);
    if (prev == nullptr) return nullptr;
    return prev - (i - 1);
}

template<class T>
bool Node<T>::operator==(const Node & n) {
    return next == n.next && prev == n.prev && value == n.value;
}
