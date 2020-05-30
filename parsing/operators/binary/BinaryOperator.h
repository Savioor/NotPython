//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_BINARYOPERATOR_H
#define BASICPYTHONINTERPRETER_BINARYOPERATOR_H


#include "../../../memory/PyClass.h"
#include "../Operator.h"
#include "../encapsulating/Brackets.h"


class BinaryOperator : public Operator {

public:

    BinaryOperator();

    virtual PyClass* reduce(PyClass* left, PyClass* right) = 0;

    virtual PyClass* reduceWithBracketContext(PyClass* left, PyClass* right, BRACKET_TYPE leftContext,
            BRACKET_TYPE rightContext);

    virtual PyClass* reduceWithFullContext(Operator* left, Operator*);

};


#endif //BASICPYTHONINTERPRETER_BINARYOPERATOR_H
