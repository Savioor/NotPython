//
// Created by USER on 6/6/2020.
//

#ifndef BASICPYTHONINTERPRETER_STRINGDEFAULT_H
#define BASICPYTHONINTERPRETER_STRINGDEFAULT_H


#include "../../functions/PyInternalFunction.h"

class StringDefault : public PyInternalFunction {

public:
    StringDefault(PyClass*);

protected:
    PyClass *process(std::map<std::string, PyClass *> &map) override;

};


#endif //BASICPYTHONINTERPRETER_STRINGDEFAULT_H
