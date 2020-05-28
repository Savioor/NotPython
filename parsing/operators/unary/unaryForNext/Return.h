//
// Created by USER on 5/28/2020.
//

#ifndef BASICPYTHONINTERPRETER_RETURN_H
#define BASICPYTHONINTERPRETER_RETURN_H


#include "UnaryForNext.h"

class Return : public UnaryForNext {

public:
    Return();

    PyClass *expand(PyClass *next) override;

};


#endif //BASICPYTHONINTERPRETER_RETURN_H
