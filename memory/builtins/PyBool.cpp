//
// Created by USER on 5/13/2020.
//

#include "PyBool.h"
#include "../../debug.h"
#include "PyString.h"
#include <iostream>

PyBool::PyBool(bool v) : value{v} {
#if MEM_ALLOC_DEBUG
    std::cout << "Allocated new boolean with value " << v << std::endl;
#endif
    type = pyBOOL;
}

PyClass *PyBool::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyBool::negate() const {
    return nullptr;
}

PyClass *PyBool::call(PyClass const &params) {
    return nullptr;
}

PyBool *PyBool::leftAnd(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyBOOL:
            return new PyBool(value && ((PyBool const&)right).getValue());

    }
    return nullptr;
}

PyBool *PyBool::leftOr(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyBOOL:
            return new PyBool(value || ((PyBool const&)right).getValue());

    }
    return nullptr;
}

PyBool *PyBool::leftEql(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyBOOL:
            return new PyBool(value == ((PyBool const&)right).getValue());

    }
    return new PyBool(false);
}

PyBool *PyBool::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyBool::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyBool::logicalNot() const {
    return new PyBool(!value);
}

const PyString *PyBool::asString() const {
    if (value) return new PyString("true");
    return new PyString("false");
}

PyClass *PyBool::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyBool::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

const bool &PyBool::getValue() const {
    return value;
}

PyClass *PyBool::getSelf() {
    return new PyBool(value);
}
