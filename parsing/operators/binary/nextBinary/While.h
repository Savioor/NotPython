//
// Created by USER on 5/30/2020.
//

#ifndef BASICPYTHONINTERPRETER_WHILE_H
#define BASICPYTHONINTERPRETER_WHILE_H


#include "NextBinary.h"

class While : public NextBinary {

public:
    While();

    PyClass *reduce(PyClass *right, PyClass *afterRight) override;

    PyClass *reduceWithFullContext(Operator *right, Operator *afterRight) override;

};


#endif //BASICPYTHONINTERPRETER_WHILE_H
