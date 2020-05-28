//
// Created by alexey on 28/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_OPERATOR_H
#define BASICPYTHONINTERPRETER_OPERATOR_H


#include "../../memory/PyClass.h"

enum OPERATOR_TYPE {

    BINARY,
    UNARY,
    UNARY_PREV,
    ENCLOSING,
    CLASS,
    BINARY_BOTH_AFTER

};

enum BRACKET_TYPE {

    BT_ROUND,
    BT_SQUARE,
    BT_SQUIG,
    BT_TRIG,
    BT_NONE

};

class Operator {

public:

    const OPERATOR_TYPE type;

    Operator(OPERATOR_TYPE);

    virtual PyClass* getAsClass() const;

    int getPrecedence();

    BRACKET_TYPE bt;


protected:
    // Lower = done later. higher = done sooner
    // Stolen from here https://introcs.cs.princeton.edu/java/11precedence/
    int precedence;


};


#endif //BASICPYTHONINTERPRETER_OPERATOR_H
