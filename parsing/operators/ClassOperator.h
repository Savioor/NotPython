//
// Created by USER on 5/6/2020.
//

#ifndef BASICPYTHONINTERPRETER_CLASSOPERATOR_H
#define BASICPYTHONINTERPRETER_CLASSOPERATOR_H


#include "Operator.h"
#include "../../memory/PyClass.h"

class ClassOperator : public Operator {
public:
    ClassOperator(PyClass*);
    PyClass *getAsClass() const override;

private:
    PyClass* val;
};


#endif //BASICPYTHONINTERPRETER_CLASSOPERATOR_H
