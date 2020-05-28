//
// Created by USER on 5/28/2020.
//

#ifndef BASICPYTHONINTERPRETER_COMMAOPERATOR_H
#define BASICPYTHONINTERPRETER_COMMAOPERATOR_H


#include "BinaryOperator.h"

class CommaOperator : public BinaryOperator {

public:
    CommaOperator();

    PyClass *reduce(PyClass *left, PyClass *right) override;

    PyClass *reduceWithBracketContext(PyClass *left, PyClass *right, BRACKET_TYPE leftContext,
                                      BRACKET_TYPE rightContext) override;

};


#endif //BASICPYTHONINTERPRETER_COMMAOPERATOR_H
