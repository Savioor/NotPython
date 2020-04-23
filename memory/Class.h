//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_CLASS_H
#define BASICPYTHONINTERPRETER_CLASS_H


class Class {

public:

    virtual Class* leftAdd(Class const& rightElem) = 0;
    virtual Class* leftMult(Class const& rightElem) = 0;
    virtual Class* leftDiv(Class const& rightElem) = 0;
    virtual Class* leftSub(Class const& rightElem) = 0;

    virtual Class* leftModulu(Class const& rightElem) = 0;

    virtual Class* negate() = 0;

    virtual Class*


};


#endif //BASICPYTHONINTERPRETER_CLASS_H
