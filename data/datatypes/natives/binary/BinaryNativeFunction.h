//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_BINARYNATIVEFUNCTION_H
#define BASICPYTHONINTERPRETER_BINARYNATIVEFUNCTION_H


#include "../../PyObject.h"

class BinaryNativeFunction : public PyObject {
protected:
    std::string name;

public:
    BinaryNativeFunction(char*);
    BinaryNativeFunction(std::string&&);

    virtual PyObject* execute(PyObject*, PyObject*) = 0;
    virtual ~BinaryNativeFunction() override = default;
    virtual const std::string& getName() const;

};


#endif //BASICPYTHONINTERPRETER_BINARYNATIVEFUNCTION_H
