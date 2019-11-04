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

    virtual AnonymousObject* asStr() = 0;

    /**
     *
     * @param other
     * @return 1 if I am bigger, -1 if I am smaller, 0 if I am equal.
     */
    virtual int compare(PyObject* other) = 0;

    virtual bool equals(PyObject* other) = 0;
};


#endif //BASICPYTHONINTERPRETER_PYPRIMITIVE_H
