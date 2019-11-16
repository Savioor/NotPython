//
// Created by alexey on 24/10/2019.
//

#include "PyObject.h"
#include "../../optimization.h"

EType &PyObject::getType() {
    return type;
}

std::map<std::string, PyObject*> &PyObject::getData() {
    return data;
}

const std::map<std::string, PyObject*> &PyObject::getData() const {
    return data;
}

PyObject *PyObject::getVariable(std::string& name) {
    if (UNLIKELY(getData().count(name) == 0)){
        return nullptr;
    }
    return getData().at(name);
}


const bool &PyObject::isConst() {
    return isConstant;
}

void PyObject::setConst(bool val) {
    isConstant = val;
}

PyObject::PyObject(EType t) : type(t) {

}

size_t PyObject::getMySize() {
    return sizeof(*this);
}
