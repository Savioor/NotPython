//
// Created by alexey on 24/10/2019.
//

#include "PyObject.h"
#include "../Memory.h"
#include "AnonymousObject.h"

const std::string &PyObject::getType() const {
    return type;
}

std::string &PyObject::getType() {
    return type;
}

std::map<std::string, int> &PyObject::getData() {
    return data;
}

const std::map<std::string, int> &PyObject::getData() const {
    return data;
}

PyObject::PyObject(std::string&& n) : type(n), data() {
}

PyObject::PyObject(char* n) : type(n), data(), isPrimitiveVar(false) {
}

PyObject *PyObject::getVariable(std::string& name) {
    if (getData().count(name) == 0){
        return nullptr;
    }
    return Memory::getInstance().getData().at(getData().at(name));
}

PyObject *PyObject::unmask() {
    if (type == "rvalue")
        return ((AnonymousObject *) this)->getObject()->unmask();
    else
        return this;
}

const bool &PyObject::isPrimitive() {
    return isPrimitiveVar;
}

PyObject *PyObject::yoink() {
    if (type == "rvalue")
        return ((AnonymousObject *) this)->releaseObject()->yoink();
    else
        return this;}
