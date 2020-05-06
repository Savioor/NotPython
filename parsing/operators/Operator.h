//
// Created by alexey on 28/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_OPERATOR_H
#define BASICPYTHONINTERPRETER_OPERATOR_H


#include "../../memory/Class.h"

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

    virtual Class* getAsClass() const;

};


#endif //BASICPYTHONINTERPRETER_OPERATOR_H
