//
// Created by USER on 5/13/2020.
//

#include "PyString.h"
#include "PyBool.h"

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

PyClass *PyString::call(PyClass const &params) {
    return nullptr;
}

const PyString *PyString::asString() const {
    return this;
}

PyClass *PyString::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyString::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

const std::string &PyString::getValue() const {
    return value;
}

PyString::PyString(std::string &&string) {
    value = string;
    type = pySTRING;
}

PyBool *PyString::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyString::leftEql(PyClass const &rightElem) const {
    return nullptr;
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
