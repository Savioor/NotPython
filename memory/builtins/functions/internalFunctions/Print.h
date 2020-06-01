//
// Created by USER on 6/1/2020.
//

#ifndef BASICPYTHONINTERPRETER_PRINT_H
#define BASICPYTHONINTERPRETER_PRINT_H


#include "../PyInternalFunction.h"

class Print : public PyInternalFunction {

public:
    Print();

protected:
    PyClass *process(std::map<std::string, PyClass *> &map) override;

};


#endif //BASICPYTHONINTERPRETER_PRINT_H
