//
// Created by alexey on 01/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYPRIMITIVE_H
#define BASICPYTHONINTERPRETER_PYPRIMITIVE_H


#include "../PyObject.h"
#include <string>

class PyPrimitive : public PyObject {
public:
    explicit PyPrimitive(EType);
    PyPrimitive() = delete;

    virtual ~PyPrimitive() = default;

    virtual PyObject* addLeft(PyObject* right) = 0;
    virtual PyObject* subLeft(PyObject* right) = 0;
    virtual PyObject* multLeft(PyObject* right) = 0;
    virtual PyObject* divLeft(PyObject* right) = 0;

    virtual std::string asStr() = 0;
    virtual int allocCopy() = 0;

    /**
     *
     * @param other
     * @return 1 if I am bigger, -1 if I am smaller, 0 if I am equal.
     */
    virtual int compare(PyObject* other) = 0;

    virtual bool equals(PyObject* other) = 0;
};


#endif //BASICPYTHONINTERPRETER_PYPRIMITIVE_H
