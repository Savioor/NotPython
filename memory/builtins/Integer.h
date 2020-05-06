//
// Created by USER on 5/5/2020.
//

#ifndef BASICPYTHONINTERPRETER_INTEGER_H
#define BASICPYTHONINTERPRETER_INTEGER_H


#include <stdint-gcc.h>
#include <cstdint>
#include "../Class.h"

class Integer : public Class {

public:
    explicit Integer(int64_t);
    ~Integer() override = default;

    int getValue() const;

    Class *leftAdd(Class const &rightElem) override;

    Class *leftMult(Class const &rightElem) override;

    Class *leftDiv(Class const &rightElem) override;

    Class *leftSub(Class const &rightElem) override;

    Class *leftModulu(Class const &rightElem) override;

    Class *leftPower(Class const &rightElem) override;

    Class *negate() override;

    Class *call(Class const &params) override;

    Class *asString() override;

    Class *getElem(Class const &indexer) override;

    Class *setElem(Class const &indexer, Class const &newElem) override;

private:
    std::int64_t value;

};


#endif //BASICPYTHONINTERPRETER_INTEGER_H
