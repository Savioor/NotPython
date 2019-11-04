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

    AnonymousObject *addLeft(PyObject *right) override;

    AnonymousObject *subLeft(PyObject *right) override;

    AnonymousObject *multLeft(PyObject *right) override;

    AnonymousObject *divLeft(PyObject *right) override;

    AnonymousObject *asStr() override;

    int compare(PyObject *other) override;

    bool equals(PyObject *other) override;
};


#endif //BASICPYTHONINTERPRETER_PYBOOLEAN_H
