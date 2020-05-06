//
// Created by USER on 5/6/2020.
//

#ifndef BASICPYTHONINTERPRETER_CLASSOPERATOR_H
#define BASICPYTHONINTERPRETER_CLASSOPERATOR_H


#include "Operator.h"
#include "../../memory/Class.h"

class ClassOperator : public Operator {
public:
    ClassOperator(Class*);
    Class *getAsClass() const override;

private:
    Class* val;
};


#endif //BASICPYTHONINTERPRETER_CLASSOPERATOR_H
