//
// Created by USER on 5/5/2020.
//

#include <ostream>
#include "PyInteger.h"
#include "PyString.h"
#include <cmath>
#include <iostream>
#include "PyBool.h"
#include "../../../debug.h"


PyClass *PyInteger::leftAdd(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(value + dynamic_cast<PyInteger const&>(right).value);
        case pyDOUBLE:

            break;
        case pySTRING:
            return new PyString(std::to_string(value) + dynamic_cast<PyString const&>(right).getValue());
    }
    return nullptr;
}

PyClass *PyInteger::leftMult(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(value * dynamic_cast<PyInteger const&>(right).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

PyClass *PyInteger::leftDiv(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(value / dynamic_cast<PyInteger const&>(right).value);
        case pyDOUBLE:

            break;
    }
    return nullptr;
}

PyClass *PyInteger::leftSub(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(value - dynamic_cast<PyInteger const&>(right).value);
        case pyDOUBLE:

            break;
    }
    return nullptr;
}

PyClass *PyInteger::leftModulu(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(value % dynamic_cast<PyInteger const&>(right).value);
        case pyDOUBLE:

            break;
    }
    return nullptr;
}

PyClass *PyInteger::leftPower(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){
        case pyINTEGER:
            return new PyInteger(std::round(std::pow(value, dynamic_cast<PyInteger const&>(right).value)));
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

PyClass *PyInteger::negate() const {
    return new PyInteger(-value);
}

PyClass *PyInteger::call(PyClass &params) {
    return nullptr;
}

const PyString *PyInteger::asString() const {
    return new PyString(std::move(std::to_string(value)));
}

PyClass *PyInteger::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyInteger::setElem(PyClass &indexer, PyClass &newElem) {
    return nullptr;
}

int PyInteger::getValue() const{
    return value;
}


PyInteger::PyInteger(int64_t val) : PyClass() {
    type = pyINTEGER;
    value = val;
#if MEM_ALLOC_DEBUG
    std::cout << "This class is an integer with value " << val << std::endl;
#endif
}

PyBool *PyInteger::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyInteger::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyInteger::leftEql(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyINTEGER:
            return new PyBool(value == ((PyInteger const&)right).getValue());
        case pyDOUBLE:
            break; // TODO

    }
    return new PyBool(false);
}

PyBool *PyInteger::leftBigger(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyINTEGER:
            return new PyBool(value > ((PyInteger const&)right).getValue());
        case pyDOUBLE:
            break; // TODO

    }
    return new PyBool(false);
}

PyBool *PyInteger::leftSmaller(PyClass const &rightElem) const {
    const PyClass& right = rightElem.getRaw();
    switch (right.type){

        case pyINTEGER:
            return new PyBool(value < ((PyInteger const&)right).getValue());
        case pyDOUBLE:
            break; // TODO

    }
    return new PyBool(false);
}

PyBool *PyInteger::logicalNot() const {
    return nullptr;
}

PyClass *PyInteger::getSelf() {
    return new PyInteger(value);
}
