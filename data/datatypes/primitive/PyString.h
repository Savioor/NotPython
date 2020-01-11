//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYSTRING_H
#define BASICPYTHONINTERPRETER_PYSTRING_H

#include "PyPrimitive.h"
#include "../PyObject.h"

class PyString : public PyPrimitive {
public:
    PyString();
    PyString(char*);
    PyString(std::string&);
    PyString(std::string&&);

    virtual ~PyString() = default;


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

    std::string myValue;

};


#endif //BASICPYTHONINTERPRETER_PYSTRING_H
