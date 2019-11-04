//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYSTRING_H
#define BASICPYTHONINTERPRETER_PYSTRING_H

#include "PyPrimitive.h"
#include "../PyObject.h"
#include "../AnonymousObject.h"

class PyString : public PyPrimitive {
public:
    PyString();
    PyString(char*);
    PyString(std::string&);
    PyString(std::string&&);

    virtual ~PyString() = default;


    virtual AnonymousObject *addLeft(PyObject *right) override;

    virtual AnonymousObject *subLeft(PyObject *right) override;

    virtual AnonymousObject *multLeft(PyObject *right) override;

    virtual AnonymousObject *divLeft(PyObject *right) override;

    virtual AnonymousObject *asStr() override;

    /**
     * 1 for bigger, -1 for smaller, 0 for equal. -2 for unsupported.
     * @param right
     * @return
     */
    virtual int compare(PyObject* right) override;
    virtual bool equals(PyObject* other) override;

    std::string myValue;

};


#endif //BASICPYTHONINTERPRETER_PYSTRING_H
