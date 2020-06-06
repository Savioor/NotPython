




//
// Created by USER on 6/5/2020.
//

#ifndef BASICPYTHONINTERPRETER_ELIF_H
#define BASICPYTHONINTERPRETER_ELIF_H


#include "TernaryOneBefore.h"

class Elif : public TernaryOneBefore {

public:
    Elif();

    Operator *reduce(std::shared_ptr<Operator> before, std::shared_ptr<Operator> after, std::shared_ptr<Operator> secondAfter) override;

};


#endif //BASICPYTHONINTERPRETER_ELIF_H
