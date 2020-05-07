//
// Created by USER on 5/7/2020.
//

#ifndef BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H
#define BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H


#include "BinaryOperator.h"

class SimpleBinaryOperator : public BinaryOperator {

public:
    SimpleBinaryOperator(int, Class* (*)(Class*, Class*));

    Class* reduce(Class* left, Class* right) override;

private:
    Class* (*operation)(Class*, Class*);
};


#endif //BASICPYTHONINTERPRETER_SIMPLEBINARYOPERATOR_H
