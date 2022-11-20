//
// Created by alexey on 31/05/2020.
//

#include "PyClassStructure.h"
#include "PyClassInstance.h"
#include "../PyVariable.h"
#include "../../MemoryManager.h"

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
    if (&params == MemoryManager::getManager().getNone()) {
        return pointerMap["__init__"]->call(*newInstance);
    } else if (params.type != pyARRAY) {
        PyList* inputList = new PyList();
        inputList->pushBack(newInstance);
        inputList->pushBack(&params);
        return pointerMap["__init__"]->call(*inputList);
    } else {
        PyList* asLs = (PyList*) (&params);
        asLs->insertBefore(newInstance, 0);
        return pointerMap["__init__"]->call(*asLs);
    }
}

const PyString *PyClassStructure::asString() const {
    return nullptr;
}

PyClass *PyClassStructure::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyClassStructure::setElem(PyClass &indexer, PyClass &newElem) {
    return nullptr;
}

PyClassStructure::PyClassStructure() {

}

PyClassStructure::PyClassStructure(int marker) {

}
