//
// Created by USER on 5/17/2020.
//

#include <stdexcept>
#include <utility>
#include "PyVariable.h"
#include "../MemoryManager.h"

PyClass *PyVariable::leftAdd(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftAdd(rightElem);
}

PyClass *PyVariable::leftMult(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftMult(rightElem);
}

PyClass *PyVariable::leftDiv(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftDiv(rightElem);
}

PyClass *PyVariable::leftSub(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftSub(rightElem);
}

PyClass *PyVariable::leftModulu(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftModulu(rightElem);
}

PyClass *PyVariable::leftPower(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftPower(rightElem);
}

PyClass *PyVariable::negate() const {
    nullptrTest();
    return child->negate();
}

PyBool *PyVariable::leftAnd(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftAnd(rightElem);
}

PyBool *PyVariable::leftOr(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftOr(rightElem);
}

PyBool *PyVariable::leftEql(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftEql(rightElem);
}

PyBool *PyVariable::leftBigger(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftBigger(rightElem);
}

PyBool *PyVariable::leftSmaller(PyClass const &rightElem) const {
    nullptrTest();
    return child->leftSmaller(rightElem);
}

PyBool *PyVariable::logicalNot() const {
    nullptrTest();
    return child->logicalNot();
}

PyClass *PyVariable::call(PyClass const &params) {
    nullptrTest();
    return child->call(params);
}

const PyString *PyVariable::asString() const {
    nullptrTest();
    return child->asString();
}

PyClass *PyVariable::getElem(PyClass const &indexer) const {
    nullptrTest();
    return child->getElem(indexer);
}

PyClass *PyVariable::setElem(PyClass const &indexer, PyClass const &newElem) {
    nullptrTest();
    return child->setElem(indexer, newElem);
}

const std::string &PyVariable::getName() const {
    return varName;
}

const PyClass *PyVariable::getChild() const {
    return child;
}

PyClass *PyVariable::getChild() {
    return child;
}

void PyVariable::setChild(PyClass * c) {
    child = c;
}

void PyVariable::nullptrTest() const {
    if (child == nullptr) {
        throw std::runtime_error("Attempting operation on un-assigned variable " + varName);
    }
}

PyVariable::PyVariable(std::string && name) : child{nullptr}, varName{name} {
    type = pyVAR;
    MemoryManager::getManager().allocateVariable(this);
}

PyVariable::PyVariable(std::string name) : child{nullptr}, varName{std::move(name)} {
    type = pyVAR;
    MemoryManager::getManager().allocateVariable(this);
}

PyClass *PyVariable::setSelf(PyClass &other) {
    if (other.type == pyOTHER) {
        child->references--;
        child = &other;
        child->references++;
    } else if (other.type == pyVAR) {
        return setSelf(*other.getSelf());
    } else {
        child->references--;
        child = other.getSelf();
        child->references++;
    }
    return child;
}

