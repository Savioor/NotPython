//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_BINARYOPERATOR_H
#define BASICPYTHONINTERPRETER_BINARYOPERATOR_H


#include "../../../memory/Class.h"
#include "../Operator.h"


class BinaryOperator : public Operator {

public:

    BinaryOperator();

    virtual Class* reduce(Class* left, Class* right) = 0;

};


#endif //BASICPYTHONINTERPRETER_BINARYOPERATOR_H
