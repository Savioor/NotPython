//
// Created by alexey on 31/05/2020.
//

#include "PyMethod.h"
#include "../../MemoryManager.h"

PyClass *PyMethod::call(PyClass &params) {
    if (&params == MemoryManager::getManager().getNone()) {
        return wrappedFunction->call(*methodOwner);
    } else if (params.type != pyARRAY) {
        PyList* inputList = new PyList();
        inputList->pushBack(methodOwner);
        inputList->pushBack(&params);
        return wrappedFunction->call(*inputList);
    } else {
        PyList* asLs = (PyList*) &params;
        asLs->insertBefore(methodOwner, 0);
        return wrappedFunction->call(*asLs);
    }
}

PyClass *PyMethod::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyMethod::negate() const {
    return nullptr;
}

PyBool *PyMethod::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyMethod::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyMethod::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyMethod::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyMethod::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyMethod::logicalNot() const {
    return nullptr;
}


const PyString *PyMethod::asString() const {
    return nullptr;
}

PyClass *PyMethod::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyMethod::setElem(PyClass &indexer, PyClass &newElem) {
    return nullptr;
}

PyMethod::PyMethod(PyFunction * m, PyClass * i) : methodOwner{i}, wrappedFunction{m} {
    pointerMap.insert({"f", m});
    pointerMap.insert({"i", methodOwner});
}
