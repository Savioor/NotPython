//
// Created by alexey on 29/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYFUNCTION_H
#define BASICPYTHONINTERPRETER_PYFUNCTION_H


#include "../PyObject.h"

class PyFunction : public PyObject {
protected:
    std::vector<std::string> inputVariables;
    std::vector<std::string> code;

public:
    PyFunction(std::vector<std::string>& code, std::vector<std::string>& vars);
    virtual ~PyFunction() = default;

    const std::vector<std::string>& getInputNames();
    PyObject* execute(std::vector<PyObject*>& input);
};


#endif //BASICPYTHONINTERPRETER_PYFUNCTION_H
