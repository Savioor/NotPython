//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_BINARYEXPRESSION_H
#define BASICPYTHONINTERPRETER_BINARYEXPRESSION_H


class BinaryExpression {

public:

    virtual Class* reduce(Class* left, Class* right) = 0;

};


#endif //BASICPYTHONINTERPRETER_BINARYEXPRESSION_H
