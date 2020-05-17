//
// Created by USER on 5/5/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYINTEGER_H
#define BASICPYTHONINTERPRETER_PYINTEGER_H


#include <stdint-gcc.h>
#include <cstdint>
#include "../PyClass.h"
#include "PyString.h"

class PyInteger : public PyClass {

public:
    explicit PyInteger(int64_t);
    ~PyInteger() override = default;

    int getValue() const;

    PyClass *leftAdd(PyClass const &rightElem) const override;

    PyClass *leftMult(PyClass const &rightElem) const override;

    PyClass *leftDiv(PyClass const &rightElem) const override;

    PyClass *leftSub(PyClass const &rightElem) const override;

    PyClass *leftModulu(PyClass const &rightElem) const override;

    PyClass *leftPower(PyClass const &rightElem) const override;

    PyClass *negate() const override;

    PyBool *leftAnd(PyClass const &rightElem) const override;

    PyBool *leftOr(PyClass const &rightElem) const override;

    PyBool *leftEql(PyClass const &rightElem) const override;

    PyBool *leftBigger(PyClass const &rightElem) const override;

    PyBool *leftSmaller(PyClass const &rightElem) const override;

    PyBool *logicalNot() const override;

    PyClass *call(PyClass const &params) override;

    const PyString *asString() const override;

    PyClass *getElem(PyClass const &indexer) const override;

    PyClass *setElem(PyClass const &indexer, PyClass const &newElem) override;

    PyClass *getSelf() override;

private:
    std::int64_t value;

};


#endif //BASICPYTHONINTERPRETER_PYINTEGER_H
