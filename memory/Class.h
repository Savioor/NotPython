//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_CLASS_H
#define BASICPYTHONINTERPRETER_CLASS_H


class Class {

public:

    // Mathematical operations
    virtual Class* leftAdd(Class const& rightElem) = 0;
    virtual Class* leftMult(Class const& rightElem) = 0;
    virtual Class* leftDiv(Class const& rightElem) = 0;
    virtual Class* leftSub(Class const& rightElem) = 0;

    // Slightly weird mathematical operations
    virtual Class* leftModulu(Class const& rightElem) = 0;
    virtual Class* leftPower(Class const& rightElem) = 0;
    virtual Class* negate() = 0;

    // TODO This should receive List const& when they exist
    virtual Class* call(Class const& params) = 0;

    // TODO this should return String* when they exist
    virtual Class* asString() = 0;

    // Array Operations
    // TODO this is kinda maybe a bad idea,
    // TODO but I'll cross that bridge when I get to it
    virtual Class* getElem(Class const& indexer) = 0;
    virtual Class* setElem(Class const& indexer,
                           Class const& newElem) = 0;

};


#endif //BASICPYTHONINTERPRETER_CLASS_H
