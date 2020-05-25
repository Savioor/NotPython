//
// Created by alexey on 25/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_UNARYFORNEXT_H
#define BASICPYTHONINTERPRETER_UNARYFORNEXT_H


#include "../../Operator.h"

class UnaryForNext : public Operator {

public:
    UnaryForNext();

    virtual PyClass* expand(PyClass* next) = 0;

};


#endif //BASICPYTHONINTERPRETER_UNARYFORNEXT_H
