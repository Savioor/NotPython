//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H
#define BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H


#include "BinaryNativeFunction.h"

class PointerAssignOperator {
public:
    PointerAssignOperator();
    pointerValuePair_t execute(pointerValuePair_t left, objectLoc_t right);
};


#endif //BASICPYTHONINTERPRETER_POINTERASSIGNOPERATOR_H
