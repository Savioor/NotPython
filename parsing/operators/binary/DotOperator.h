//
// Created by alexey on 31/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_DOTOPERATOR_H
#define BASICPYTHONINTERPRETER_DOTOPERATOR_H


#include "BinaryOperator.h"

class DotOperator : public BinaryOperator {

public:
    DotOperator();

    PyClass *reduce(PyClass *left, PyClass *right) override;

};


#endif //BASICPYTHONINTERPRETER_DOTOPERATOR_H
