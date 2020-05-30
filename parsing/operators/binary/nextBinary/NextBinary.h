//
// Created by alexey on 26/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_NEXTBINARY_H
#define BASICPYTHONINTERPRETER_NEXTBINARY_H


#include "../BinaryOperator.h"

class NextBinary : public Operator {

public:

    NextBinary();

    virtual PyClass* reduce(PyClass* right, PyClass* afterRight) = 0;

    virtual PyClass* reduceWithFullContext(Operator* right, Operator* afterRight);


};


#endif //BASICPYTHONINTERPRETER_NEXTBINARY_H
