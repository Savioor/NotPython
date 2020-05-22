//
// Created by USER on 5/22/2020.
//

#ifndef BASICPYTHONINTERPRETER_ROUNDBRACKETS_H
#define BASICPYTHONINTERPRETER_ROUNDBRACKETS_H


#include "Brackets.h"

class RoundBrackets : public Brackets {

public:
    RoundBrackets();

    EncapsulatingOperator *supplySelf() override;

    PyClass *getAsClass() const override;

};


#endif //BASICPYTHONINTERPRETER_ROUNDBRACKETS_H
