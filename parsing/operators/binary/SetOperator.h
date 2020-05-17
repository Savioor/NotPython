//
// Created by USER on 5/17/2020.
//

#ifndef BASICPYTHONINTERPRETER_SETOPERATOR_H
#define BASICPYTHONINTERPRETER_SETOPERATOR_H


#include "BinaryOperator.h"

class SetOperator : public BinaryOperator {

public:
    SetOperator();

    PyClass *reduce(PyClass *left, PyClass *right) override;

};


#endif //BASICPYTHONINTERPRETER_SETOPERATOR_H
