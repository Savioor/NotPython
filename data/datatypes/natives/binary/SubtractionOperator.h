//
// Created by alexey on 08/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_SUBTRACTIONOPERATOR_H
#define BASICPYTHONINTERPRETER_SUBTRACTIONOPERATOR_H


#include "BinaryNativeFunction.h"

class SubtractionOperator : public BinaryNativeFunction{
public:
    SubtractionOperator();
    objectLoc_t execute(objectLoc_t left, objectLoc_t right) override;
};


#endif //BASICPYTHONINTERPRETER_SUBTRACTIONOPERATOR_H
