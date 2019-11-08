//
// Created by alexey on 08/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_MULTIPLICATIONOPERATOR_H
#define BASICPYTHONINTERPRETER_MULTIPLICATIONOPERATOR_H


#include "BinaryNativeFunction.h"

class MultiplicationOperator : public BinaryNativeFunction{
public:
    MultiplicationOperator();
    PyObject *execute(PyObject *left, PyObject *right) override;

};


#endif //BASICPYTHONINTERPRETER_MULTIPLICATIONOPERATOR_H
