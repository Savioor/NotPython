//
// Created by USER on 6/5/2020.
//

#ifndef BASICPYTHONINTERPRETER_TERNARYONEBEFORE_H
#define BASICPYTHONINTERPRETER_TERNARYONEBEFORE_H


#include <memory>
#include "../Operator.h"

class TernaryOneBefore : public Operator {

public:
    TernaryOneBefore();

    virtual Operator* reduce(std::shared_ptr<Operator> before, std::shared_ptr<Operator> after, std::shared_ptr<Operator> secondAfter) = 0;

};


#endif //BASICPYTHONINTERPRETER_TERNARYONEBEFORE_H
