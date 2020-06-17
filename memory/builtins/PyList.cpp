//
// Created by USER on 5/22/2020.
//

#include "PyList.h"
#include "primitive/PyString.h"
#include "primitive/PyInteger.h"
#include "classes/PyMethod.h"
#include "PyVariable.h"
#include "functions/internalFunctions/listFunctions/Append.h"
#include "../MemoryManager.h"

PyClass *PyList::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyList::negate() const {
    return nullptr;
}

PyBool *PyList::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyList::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyList::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyList::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyList::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyList::logicalNot() const {
    return nullptr;
}

PyClass *PyList::call(PyClass &params) {
    return nullptr;
}

const PyString *PyList::asString() const {
    std::string repr = "{";
    for (auto c : ls){
        repr += c->asString()->getValue();
        repr += ", ";
    }
    repr += "}";
    return new PyString(std::move(repr));
}

PyClass *PyList::getElem(PyClass &indexer) const {
    PyClass& indexerUnwrapped = indexer.getRaw();
    if(indexerUnwrapped.type != pyINTEGER) {
        throw std::runtime_error("List get operator expected integer");
    }
    PyInteger& asInt = (PyInteger&) indexerUnwrapped;
    if (asInt.getValue() < 0 || asInt.getValue() >= ls.size()) {
        throw std::runtime_error("Index out of bounds exception");
    }
    return ls.at(asInt.getValue());
}

PyClass *PyList::setElem(PyClass &indexer, PyClass &newElem) {
    PyClass& indexerUnwrapped = indexer.getRaw();
    PyClass& newElemUnwrapped = newElem.getRaw();
    if(indexerUnwrapped.type != pyINTEGER) {
        throw std::runtime_error("List get operator expected integer");
    }
    PyInteger& asInt = (PyInteger&) indexerUnwrapped;
    if (asInt.getValue() < 0 || asInt.getValue() >= ls.size()) {
        throw std::runtime_error("Index out of bounds exception");
    }
    ls[asInt.getValue()] = &newElem;
    return MemoryManager::getManager().getNone();
}

PyList::PyList() : ls{} {
    static Append* appendFunc = new Append();

    type = pyARRAY;
    pointerMap.insert({"append", new PyVariable(new PyMethod(appendFunc, this))});
}

std::vector<PyClass *> &PyList::getElements() {
    return ls;
}

void PyList::insertBefore(PyClass * cls, int ind) {
    ls.insert(ls.begin() + ind, new PyVariable("", &cls->getRaw()));
}

void PyList::pushBack(PyClass* cls) {
    ls.push_back(new PyVariable("", &cls->getRaw()));
}

PyList::PyList(int marker) {
    type = pyARRAY;
}
