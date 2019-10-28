//
// Created by alexey on 24/10/2019.
//

#include "PyObject.h"

#include <utility>
#include "../Memory.h"

const std::string &PyObject::getType() const {
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

PyObject::PyObject(char* n) : type(n), data() {
}

PyObject *PyObject::getVariable(std::string& name) {
    if (getData().count(name) == 0){
        return nullptr;
    }
    return Memory::getInstance().getData().at(getData().at(name));
}
