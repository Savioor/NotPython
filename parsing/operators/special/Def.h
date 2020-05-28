//
// Created by USER on 5/28/2020.
//

#ifndef BASICPYTHONINTERPRETER_DEF_H
#define BASICPYTHONINTERPRETER_DEF_H


#include "../Operator.h"
#include "TernaryAllAfter.h"

class Def : public TernaryAllAfter {

public:
    Def();

    PyClass *reduce(PyClass *first, PyClass *second, PyClass *third) override;

};


#endif //BASICPYTHONINTERPRETER_DEF_H
