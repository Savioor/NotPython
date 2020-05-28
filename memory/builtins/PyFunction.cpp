//
// Created by USER on 5/28/2020.
//

#include "PyFunction.h"

PyClass *PyFunction::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyFunction::negate() const {
    return nullptr;
}

PyBool *PyFunction::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyFunction::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyFunction::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyFunction::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyFunction::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyFunction::logicalNot() const {
    return nullptr;
}

PyClass *PyFunction::call(PyClass const &params) {
//    if (params)
    return nullptr;
}

const PyString *PyFunction::asString() const {
    return nullptr;
}

PyClass *PyFunction::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyFunction::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

// params is PyList or None
PyFunction::PyFunction(PyClass * params, PyCodeblock * block) {
    type = pyFUNCTION;

    pointerMap.insert({"p", params});
    pointerMap.insert({"b", block});

}
