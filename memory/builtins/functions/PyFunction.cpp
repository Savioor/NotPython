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

    PyClass* myParams = pointerMap["p"];
    PyClass* None = MemoryManager::getManager().getNone();
    PyClass* ret = nullptr;

    if (&params == None && myParams == None) {
        ret = ((PyCodeblock*)pointerMap["b"])->execute();
    } else if (params.type != pyARRAY) {
        if (myParams->type != pyARRAY && myParams != None) {
            (new PyVariable(((PyVariable*)myParams)->getName()))->setSelf(params);
            ret = ((PyCodeblock*)pointerMap["b"])->execute();
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
            inputName = inputNameList.getElements().at(i);

            if (inputName->type != pyVAR) {
                throw std::runtime_error("one of functions input variables isnt PyVariable");
            }

            (new PyVariable(((PyVariable*)inputName)->getName()))->setSelf(*input);
        }

        ret = ((PyCodeblock*)pointerMap["b"])->execute();


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
