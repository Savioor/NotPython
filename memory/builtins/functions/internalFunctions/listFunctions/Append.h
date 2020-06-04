//
// Created by alexey on 03/06/2020.
//

#ifndef BASICPYTHONINTERPRETER_APPEND_H
#define BASICPYTHONINTERPRETER_APPEND_H


#include "../../PyInternalFunction.h"

class Append : public PyInternalFunction {

public:
    Append();

protected:
    PyClass *process(std::map<std::string, PyClass *> &map) override;

};


#endif //BASICPYTHONINTERPRETER_APPEND_H
