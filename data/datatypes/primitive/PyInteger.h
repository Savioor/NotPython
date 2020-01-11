//
// Created by alexey on 06/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYINTEGER_H
#define BASICPYTHONINTERPRETER_PYINTEGER_H


#include "PyPrimitive.h"

class PyInteger : public PyPrimitive {
public:
    PyInteger();
    PyInteger(long);

    virtual ~PyInteger() = default;


    virtual objectLoc_t addLeft(objectLoc_t right) override;

    virtual objectLoc_t subLeft(objectLoc_t right) override;

    virtual objectLoc_t multLeft(objectLoc_t right) override;

    virtual objectLoc_t divLeft(objectLoc_t right) override;

    virtual std::string asStr() override;

    virtual objectLoc_t allocCopy() override;

    /**
     * 1 for bigger, -1 for smaller, 0 for equal. -2 for unsupported.
     * @param right
     * @return
     */
    virtual int compare(objectLoc_t right) override;
    virtual bool equals(objectLoc_t other) override;

    long myValue;
};


#endif //BASICPYTHONINTERPRETER_PYINTEGER_H
