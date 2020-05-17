//
// Created by alexey on 28/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_OPERATOR_H
#define BASICPYTHONINTERPRETER_OPERATOR_H


#include "../../memory/PyClass.h"

enum OPERATOR_TYPE {

    BINARY,
    UNARY,
    ENCLOSING,
    CLASS

};

class Operator {

public:

    const OPERATOR_TYPE type;

    Operator(OPERATOR_TYPE);

    virtual PyClass* getAsClass() const;

    int getPrecedence();

protected:
    // Lower = done later. higher = done sooner
    // Stolen from here https://introcs.cs.princeton.edu/java/11precedence/
    int precedence;


};


#endif //BASICPYTHONINTERPRETER_OPERATOR_H
