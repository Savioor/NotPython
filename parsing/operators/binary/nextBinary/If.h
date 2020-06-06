//
// Created by alexey on 26/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_IF_H
#define BASICPYTHONINTERPRETER_IF_H


#include "NextBinary.h"

class If : public NextBinary {
public:
    If();
    Operator *reduce(PyClass *right, PyClass *afterRight) override;
    Operator *reduceWithFullContext(std::shared_ptr<Operator>& right, std::shared_ptr<Operator>& afterRight) override;

};


#endif //BASICPYTHONINTERPRETER_IF_H
