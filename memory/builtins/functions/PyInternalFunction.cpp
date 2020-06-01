//
// Created by USER on 6/1/2020.
//

#include "PyInternalFunction.h"
#include "../../MemoryManager.h"
#include "../PyVariable.h"

PyClass *PyInternalFunction::call(PyClass &params) {
    MemoryManager::getManager().increaseStackDepth();

    PyClass* myParams = pointerMap["p"];
    PyClass* None = MemoryManager::getManager().getNone();
    PyClass* ret = nullptr;
    std::map<std::string, PyClass*> input;

    if (&params == None && myParams == None) {
        // TODO this is stupid but so am I
    } else if (params.type != pyARRAY) {

        if (myParams->type != pyARRAY && myParams != None) {
            input.insert({((PyVariable*)myParams)->getName(), &params});
        } else {
            throw std::runtime_error("Input parameter amount doesn't match function signature");
        }

    } else if (params.type == pyARRAY && myParams->type == pyARRAY) {

        PyList& inputList = (PyList&) params;
        PyList& inputNameList = (PyList&) *myParams;

        if (inputList.getElements().size() != inputNameList.getElements().size()) {
            throw std::runtime_error("Input parameter amount doesn't match function signature");
        }

        PyClass* value;
        PyClass* inputName;

        for (int i = 0; i < inputList.getElements().size(); i++){
            value = inputList.getElements().at(i);
            inputName = inputNameList.getElements().at(i);

            if (inputName->type != pyVAR) {
                throw std::runtime_error("one of functions input variables isnt PyVariable");
            }

            input.insert({((PyVariable*)myParams)->getName(), value});
        }


    } else {
        throw std::runtime_error("Input parameter amount doesn't match function signature");
    }

    ret = process(input);

    ret->isReturnValue = false;
    ret->expressionDepth = MemoryManager::getManager().getCurrentDepth(); // TODO test this specific line
    MemoryManager::getManager().classesByExpDepth.at(ret->expressionDepth - 1)->push_back(ret);

    MemoryManager::getManager().decreaseStackDepth();
    return ret;
}

PyInternalFunction::PyInternalFunction(PyClass * inputList)
        : PyFunction(inputList, nullptr){}
