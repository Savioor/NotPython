//
// Created by alexey on 25/05/2020.
//

#include "PyCodeblock.h"

PyClass *PyCodeblock::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::negate() const {
    return nullptr;
}

PyBool *PyCodeblock::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::logicalNot() const {
    return nullptr;
}

PyClass *PyCodeblock::call(PyClass const &params) {
    return nullptr;
}

const PyString *PyCodeblock::asString() const {
    return nullptr;
}

PyClass *PyCodeblock::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyCodeblock::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

PyClass *PyCodeblock::execute() {
    return nullptr;
}

PyCodeblock::PyCodeblock(std::string &&code) : code{code} {

}
