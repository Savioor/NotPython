//
// Created by alexey on 28/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_ADDITION_H
#define BASICPYTHONINTERPRETER_ADDITION_H


#include "BinaryOperator.h"

class Addition : public BinaryOperator {

public:

    Addition();

    Class* reduce(Class* left, Class* right) override;

};


#endif //BASICPYTHONINTERPRETER_ADDITION_H
