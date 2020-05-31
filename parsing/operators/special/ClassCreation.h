//
// Created by alexey on 31/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_CLASSCREATION_H
#define BASICPYTHONINTERPRETER_CLASSCREATION_H


#include "TernaryAllAfter.h"

class ClassCreation : public TernaryAllAfter {

public:
    ClassCreation();

    PyClass *reduce(PyClass *first, PyClass *second, PyClass *third) override;

};


#endif //BASICPYTHONINTERPRETER_CLASSCREATION_H
