//
// Created by alexey on 26/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_NEXTBINARY_H
#define BASICPYTHONINTERPRETER_NEXTBINARY_H


#include <memory>
#include "../BinaryOperator.h"

class NextBinary : public Operator {

public:

    NextBinary();

    virtual Operator* reduce(PyClass* right, PyClass* afterRight) = 0;

    virtual Operator* reduceWithFullContext(std::shared_ptr<Operator>& right, std::shared_ptr<Operator>& afterRight);


};


#endif //BASICPYTHONINTERPRETER_NEXTBINARY_H
