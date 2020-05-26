//
// Created by alexey on 25/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_PRINT_H
#define BASICPYTHONINTERPRETER_PRINT_H


#include "UnaryForNext.h"

class Print : public UnaryForNext {

public:
    Print();

    PyClass *expand(PyClass *next) override;

};


#endif //BASICPYTHONINTERPRETER_PRINT_H
