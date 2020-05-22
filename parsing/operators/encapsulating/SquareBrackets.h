//
// Created by USER on 5/22/2020.
//

#ifndef BASICPYTHONINTERPRETER_SQUAREBRACKETS_H
#define BASICPYTHONINTERPRETER_SQUAREBRACKETS_H


#include "Brackets.h"

class SquareBrackets : public Brackets {

public:
    SquareBrackets();

    EncapsulatingOperator *supplySelf() override;

    PyClass *getAsClass() const override;

};


#endif //BASICPYTHONINTERPRETER_SQUAREBRACKETS_H
