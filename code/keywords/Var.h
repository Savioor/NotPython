//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_VAR_H
#define BASICPYTHONINTERPRETER_VAR_H


#include "AbstractKeyword.h"

class Var : public AbstractKeyword {
protected:
    void deleteIfRValue(PyObject*);

public:
    virtual ~Var() = default;
    Var();

    stringIter_t &parse(stringIter_t &ip, stringIter_t &end) override;
};


#endif //BASICPYTHONINTERPRETER_VAR_H
