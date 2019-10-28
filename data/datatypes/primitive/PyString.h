//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYSTRING_H
#define BASICPYTHONINTERPRETER_PYSTRING_H


#include "../PyObject.h"

class PyString : public PyObject {
public:
    PyString();
    PyString(char*);
    PyString(std::string&);
    PyString(std::string&&);

    virtual ~PyString() = default;

    std::string myValue;

};


#endif //BASICPYTHONINTERPRETER_PYSTRING_H
