//
// Created by alexey on 27/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_UNARYNATIVEFUNCTION_H
#define BASICPYTHONINTERPRETER_UNARYNATIVEFUNCTION_H


#include "../../PyObject.h"
#include "../../../memory-structure/PoolMaster.h"

class UnaryNativeFunction : public PyObject {
public:
    UnaryNativeFunction();

    virtual objectLoc_t execute(objectLoc_t) = 0;

    virtual ~UnaryNativeFunction() = default;
};


#endif //BASICPYTHONINTERPRETER_UNARYNATIVEFUNCTION_H
