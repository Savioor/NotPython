//
// Created by alexey on 01/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYPRIMITIVE_H
#define BASICPYTHONINTERPRETER_PYPRIMITIVE_H


#include "../PyObject.h"
#include "../AnonymousObject.h"
#include <string>

class PyPrimitive : public PyObject {
public:
    explicit PyPrimitive(char*);
    explicit PyPrimitive(std::string&&);
    PyPrimitive() = delete;

    virtual ~PyPrimitive() = default;

    virtual AnonymousObject* addLeft(PyObject* right) = 0;
    virtual AnonymousObject* subLeft(PyObject* right) = 0;
    virtual AnonymousObject* multLeft(PyObject* right) = 0;
    virtual AnonymousObject* divLeft(PyObject* right) = 0;

    virtual AnonymousObject* asStr(PyObject* right) = 0;
};


#endif //BASICPYTHONINTERPRETER_PYPRIMITIVE_H
