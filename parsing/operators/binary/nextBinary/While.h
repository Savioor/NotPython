//
// Created by USER on 5/30/2020.
//

#ifndef BASICPYTHONINTERPRETER_WHILE_H
#define BASICPYTHONINTERPRETER_WHILE_H


#include "NextBinary.h"

class While : public NextBinary {

public:
    While();

    Operator *reduce(PyClass *right, PyClass *afterRight) override;

    Operator *reduceWithFullContext(std::shared_ptr<Operator>& right, std::shared_ptr<Operator>& afterRight) override;

};


#endif //BASICPYTHONINTERPRETER_WHILE_H
