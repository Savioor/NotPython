//
// Created by alexey on 31/05/2020.
//

#include "PyClassStructure.h"
#include "PyClassInstance.h"

PyClass *PyClassStructure::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyClassStructure::negate() const {
    return nullptr;
}

PyBool *PyClassStructure::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassStructure::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassStructure::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassStructure::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassStructure::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyClassStructure::logicalNot() const {
    return nullptr;
}

PyClass *PyClassStructure::call(PyClass &params) {
    PyClassInstance* newInstance = new PyClassInstance(this);
    return pointerMap["__init__"]->call(*newInstance);
}

const PyString *PyClassStructure::asString() const {
    return nullptr;
}

PyClass *PyClassStructure::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyClassStructure::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

PyClassStructure::PyClassStructure() {

//    pointerMap.insert({"__str__", nullptr});
//    pointerMap.insert({"__init__", nullptr});

}
