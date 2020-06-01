//
// Created by USER on 6/1/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYINTERNALFUNCTION_H
#define BASICPYTHONINTERPRETER_PYINTERNALFUNCTION_H


#include "PyFunction.h"

class PyInternalFunction : public PyFunction {

public:
    PyInternalFunction(PyClass*);

    PyClass *call(PyClass &params) override;

protected:
    virtual PyClass* process(std::map<std::string, PyClass*>&) = 0;

};


#endif //BASICPYTHONINTERPRETER_PYINTERNALFUNCTION_H
