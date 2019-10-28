//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H
#define BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H


#include "BinaryNativeFunction.h"

class PointerAssignOperator : public BinaryNativeFunction {
public:
    PointerAssignOperator();
    PyObject *execute(PyObject *left, PyObject *right) override;
};


#endif //BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H
