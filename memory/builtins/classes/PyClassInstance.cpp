//
// Created by alexey on 31/05/2020.
//

#include "PyClassInstance.h"

PyClass *PyClassInstance::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassInstance::negate() const {
    return nullptr;
}

PyBool *PyClassInstance::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassInstance::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassInstance::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassInstance::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassInstance::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassInstance::logicalNot() const {
    return nullptr;
}

PyClass *PyClassInstance::call(PyClass &params) {
    return nullptr;
}

const PyString *PyClassInstance::asString() const {
    return nullptr;
}

PyClass *PyClassInstance::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyClassInstance::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

PyClassInstance::PyClassInstance(PyClassStructure* strct) : type{strct} {

    // TODO generate all methods

}
