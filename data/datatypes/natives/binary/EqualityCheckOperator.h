//
// Created by alexey on 06/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_EQUALITYCHECKOPERATOR_H
#define BASICPYTHONINTERPRETER_EQUALITYCHECKOPERATOR_H


#include "BinaryNativeFunction.h"

class EqualityCheckOperator : public BinaryNativeFunction {
public:
    EqualityCheckOperator();
    PyObject *execute(PyObject *left, PyObject *right) override;
};


#endif //BASICPYTHONINTERPRETER_EQUALITYCHECKOPERATOR_H
