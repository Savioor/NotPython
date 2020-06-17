//
// Created by USER on 5/28/2020.
//

#include "PyFunction.h"
#include "../PyVariable.h"
#include "../../MemoryManager.h"

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

PyClass *PyFunction::call(PyClass &params) {
    MemoryManager::getManager().increaseStackDepth();

    PyClass* myParams = retrievePointed("p");
    PyClass* None = MemoryManager::getManager().getNone();
    PyClass* ret = nullptr;

    if (&params == None && myParams == None) {
        ret = ((PyCodeblock*)retrievePointed("b"))->execute();
    } else if (params.type != pyARRAY) {
        if (myParams->type != pyARRAY && myParams != None) {
            (new PyVariable(((PyVariable*)myParams)->getName()))->setSelf(params);
            ret = ((PyCodeblock*)retrievePointed("b"))->execute();
        } else {
            throw std::runtime_error("Input parameter amount doesn't match function signature");
        }
    } else if (params.type == pyARRAY && myParams->type == pyARRAY) {

        PyList& inputList = (PyList&) params;
        PyList& inputNameList = (PyList&) *myParams;

        if (inputList.getElements().size() != inputNameList.getElements().size()) {
            throw std::runtime_error("Input parameter amount doesn't match function signature");
        }

        PyClass* input;
        PyClass* inputName;

        for (int i = 0; i < inputList.getElements().size(); i++){
            input = inputList.getElements().at(i);
            inputName = ((PyVariable*)inputNameList.getElements().at(i))->getChild();

            if (inputName->type != pyVAR) {
                throw std::runtime_error("one of functions input variables isnt PyVariable");
            }

            (new PyVariable(((PyVariable*)inputName)->getName()))->setSelf(*input);
        }

        ret = ((PyCodeblock*)retrievePointed("b"))->execute();


    } else {
        throw std::runtime_error("Input parameter amount doesn't match function signature");
    }

    ret->isReturnValue = false;
    ret->expressionDepth = MemoryManager::getManager().getCurrentDepth(); // TODO test this specific line
    MemoryManager::getManager().classesByExpDepth.at(ret->expressionDepth - 1)->push_back(ret);

    MemoryManager::getManager().decreaseStackDepth();
    return ret;
}

const PyString *PyFunction::asString() const {
    return nullptr;
}

PyClass *PyFunction::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyFunction::setElem(PyClass &indexer, PyClass &newElem) {
    return nullptr;
}

// params is PyList or None
PyFunction::PyFunction(PyClass * params, PyCodeblock * block) : PyClass() {
    type = pyFUNCTION;

    pointerMap.insert({"p", new PyVariable(params)});
    pointerMap.insert({"b", new PyVariable(block)});
}
