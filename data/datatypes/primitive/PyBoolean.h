//
// Created by alexey on 03/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYBOOLEAN_H
#define BASICPYTHONINTERPRETER_PYBOOLEAN_H


#include "PyPrimitive.h"

class PyBoolean : public PyPrimitive {

public:
    bool value;

    PyBoolean(bool val);

    objectLoc_t addLeft(objectLoc_t right) override;

    objectLoc_t subLeft(objectLoc_t right) override;

    objectLoc_t multLeft(objectLoc_t right) override;

    objectLoc_t divLeft(objectLoc_t right) override;

    std::string asStr() override;

    virtual objectLoc_t allocCopy() override;

    int compare(objectLoc_t other) override;

    bool equals(objectLoc_t other) override;
};


#endif //BASICPYTHONINTERPRETER_PYBOOLEAN_H
