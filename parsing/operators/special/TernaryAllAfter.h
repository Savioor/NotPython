//
// Created by USER on 5/28/2020.
//

#ifndef BASICPYTHONINTERPRETER_TERNARYALLAFTER_H
#define BASICPYTHONINTERPRETER_TERNARYALLAFTER_H


#include "../Operator.h"

class TernaryAllAfter : public Operator {

public:
    TernaryAllAfter();

    virtual PyClass* reduce(PyClass* first, PyClass* second, PyClass* third) = 0;

};


#endif //BASICPYTHONINTERPRETER_TERNARYALLAFTER_H
