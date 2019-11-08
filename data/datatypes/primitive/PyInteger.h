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


    virtual AnonymousObject *addLeft(PyObject *right) override;

    virtual AnonymousObject *subLeft(PyObject *right) override;

    virtual AnonymousObject *multLeft(PyObject *right) override;

    virtual AnonymousObject *divLeft(PyObject *right) override;

    virtual std::string asStr() override;

    virtual int allocCopy() override;

    /**
     * 1 for bigger, -1 for smaller, 0 for equal. -2 for unsupported.
     * @param right
     * @return
     */
    virtual int compare(PyObject* right) override;
    virtual bool equals(PyObject* other) override;

    long myValue;
};


#endif //BASICPYTHONINTERPRETER_PYINTEGER_H
