//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_BINARYOPERATOR_H
#define BASICPYTHONINTERPRETER_BINARYOPERATOR_H


#include "../../../memory/PyClass.h"
#include "../Operator.h"


class BinaryOperator : public Operator {

public:

    BinaryOperator();

    virtual PyClass* reduce(PyClass* left, PyClass* right) = 0;

};


#endif //BASICPYTHONINTERPRETER_BINARYOPERATOR_H
