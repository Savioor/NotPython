//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_LINKEDLIST_H
#define BASICPYTHONINTERPRETER_LINKEDLIST_H

#include "Node.h"
#include "../data/datatypes/PyObject.h"

template <class T>
class LinkedList {

protected:
    Node<T>* startNode;
    Node<T>* endNode;

public:
    virtual int size(){
        int count = 0;
        Node<T>* counter = startNode;
        while(counter != nullptr){
            count++;
            counter = (*counter + 1);
        }
        return count;
    };
    virtual Node<T>* at(int i){
        if (startNode == nullptr) return nullptr;
        return *startNode + i;
    };
    virtual T valueAt(int i){
        return (*startNode + i)->value;
    };
    virtual void disconnect(int i){
        if (startNode == nullptr)
            return;
        disconnect(at(i));
    };
    virtual void disconnectAndKeepAlive(int i){
        if (startNode == nullptr)
            return;
        disconnectAndKeepAlive(at(i));
    };
    virtual void connectAfter(int i, Node<T>* node){
        if (startNode == nullptr){
            startNode = node;
            endNode = node;
            return;
        }
        connectAfter(at(i), node);
    };
    virtual void connectBefore(int i, Node<T>* node){
        if (startNode == nullptr){
            startNode = node;
            endNode = node;
            return;
        }
        connectBefore(at(i), node);
    };

    virtual void addToFront(Node<T>* n){
        connectBefore(0, n);
    };
    virtual void addToBack(Node<T>* n){
        if (startNode == nullptr){
            startNode = n;
            endNode = n;
            return;
        }
        endNode->next = n;
        n->prev = endNode;
        endNode = n;
    };

    virtual void connectAfterV(int i, T val){
        auto* toAdd = new Node<T>(val);
        connectAfter(i, toAdd);
    };
    virtual void connectBeforeV(int i, T val){
        auto* toAdd = new Node<T>(val);
        connectBefore(i, toAdd);
    };

    virtual void addToFrontV(T val){
        auto* toAdd = new Node<T>(val);
        addToFront(toAdd);
    };
    virtual void addToBackV(T val){
        auto* toAdd = new Node<T>(val);
        addToBack(toAdd);
    };

    virtual void connectAfterV(Node<T>* n, T val){
        auto* toAdd = new Node<T>(val);
        connectAfter(n, toAdd);
    };
    virtual void connectBeforeV(Node<T>* n, T val){
        auto* toAdd = new Node<T>(val);
        connectBefore(n, toAdd);
    };

    virtual void disconnect(Node<T>* n){
        disconnectAndKeepAlive(n);
        if (n != nullptr)
            delete n;
    };
    virtual void disconnectAndKeepAlive(Node<T>* n){
        Node<T>* bef = n->prev;
        Node<T>* aft = n->next;

        if (bef != nullptr) {
            bef->next = aft;
        }
        else {
            startNode = aft;
        }
        if (aft != nullptr) {
            aft->prev = bef;
        }
        else {
            endNode = bef;
        }

        n->prev = nullptr;
        n->next = nullptr;
    };

    virtual void connectAfter(Node<T>* location, Node<T>* node){
        Node<T>* after = *location + 1;
        location->next = node;
        node->prev = location;
        node->next = after;
        if (after != nullptr) after->prev = node;
        else endNode = node;
    };
    /**
     * Connect second to first
     * @param n
     * @param node
     */
    virtual void connectBefore(Node<T>* location, Node<T>* node){
        Node<T>* before = *location - 1;
        if (before != nullptr) before->next = node;
        else startNode = node;
        node->prev = before;
        node->next = location;
        location->prev = node;
    };

    virtual bool empty(){
        return startNode == nullptr;
    };

    virtual Node<T>* getStart(){
        return startNode;
    };
    virtual Node<T>* getEnd(){
        return endNode;
    };

    void clear(){
        startNode = nullptr;
        endNode = nullptr;
    }

    LinkedList(){
        startNode = nullptr;
        endNode = nullptr;
    };

    LinkedList(LinkedList&& ls){
        startNode = ls.getStart();
        endNode = ls.getEnd();
        ls.clear();
    }

    void operator=(LinkedList&& ls){
        startNode = ls.getStart();
        endNode = ls.getEnd();
        ls.clear();
    }

    virtual ~LinkedList(){
        if (startNode == nullptr)
            return;
        delete(startNode);
    };
};


#endif //BASICPYTHONINTERPRETER_LINKEDLIST_H
