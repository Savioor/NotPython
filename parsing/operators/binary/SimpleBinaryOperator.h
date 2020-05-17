//
// Created by USER on 5/7/2020.
//

#ifndef BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H
#define BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H


#include "BinaryOperator.h"

class SimpleBinaryOperator : public BinaryOperator {

public:
    SimpleBinaryOperator(int, PyClass* (*)(PyClass*, PyClass*));

    PyClass* reduce(PyClass* left, PyClass* right) override;

private:
    PyClass* (*operation)(PyClass*, PyClass*);
};


#endif //BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H
