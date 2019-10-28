//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_ASSIGNOPERATOR_H
#define BASICPYTHONINTERPRETER_ASSIGNOPERATOR_H


#include "BinaryNativeFunction.h"

class AssignOperator : public BinaryNativeFunction {
public:
    AssignOperator();
    PyObject *execute(PyObject *left, PyObject *right) override;
};


#endif //BASICPYTHONINTERPRETER_ASSIGNOPERATOR_H
