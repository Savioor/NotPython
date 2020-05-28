//
// Created by USER on 5/22/2020.
//

#include "PyList.h"
#include "primitive/PyString.h"
#include "primitive/PyInteger.h"

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

PyClass *PyList::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyList::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

PyList::PyList() : ls{} {
    type = pyARRAY;
}

std::vector<PyClass *> &PyList::getElements() {
    return ls;
}

void PyList::insertBefore(PyClass * cls, int ind) {
    ls.insert(ls.begin() + ind, cls);
}

void PyList::pushBack(PyClass* cls) {
    ls.push_back(cls);
}
