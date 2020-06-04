//
// Created by USER on 5/13/2020.
//

#include "PyString.h"
#include "PyBool.h"
#include "../../../debug.h"
#include <iostream>

PyClass *PyString::leftAdd(PyClass const &rightElem) const {
    const PyString* other = (PyString*)rightElem.asString();
    if (other == nullptr) return nullptr;
    return new PyString(value + other->getValue());
}

PyClass *PyString::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyString::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyString::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyString::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyString::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyString::negate() const {
    return nullptr;
}

PyClass *PyString::call(PyClass &params) {
    return nullptr;
}

const PyString *PyString::asString() const {
    return this;
}

PyClass *PyString::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyString::setElem(PyClass &indexer, PyClass &newElem) {
    return nullptr;
}

const std::string &PyString::getValue() const {
    return value;
}

PyString::PyString(std::string &&string) : value{string} {
#if MEM_ALLOC_DEBUG
    std::cout << "Allocated new string with value " << value << std::endl;
#endif
    type = pySTRING;
}

PyBool *PyString::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::leftEql(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pySTRING:
            return new PyBool(value == ((PyString const&)right).getValue());

    }
    return new PyBool(false);
}

PyBool *PyString::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::logicalNot() const {
    return nullptr;
}

PyClass *PyString::getSelf() {
    return new PyString(std::move(*(new std::string(value)))); // TODO this might be a horrible idea
}
