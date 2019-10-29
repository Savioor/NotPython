//
// Created by alexey on 29/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_ADDITIONOPERATOR_H
#define BASICPYTHONINTERPRETER_ADDITIONOPERATOR_H


#include "BinaryNativeFunction.h"

class AdditionOperator : public BinaryNativeFunction {
public:
    AdditionOperator();
    PyObject *execute(PyObject *left, PyObject *right) override;
};


#endif //BASICPYTHONINTERPRETER_ADDITIONOPERATOR_H
