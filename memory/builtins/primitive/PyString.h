//
// Created by USER on 5/13/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYSTRING_H
#define BASICPYTHONINTERPRETER_PYSTRING_H


#include <string>
#include "../../PyClass.h"

class PyString : public PyClass {

public:
    PyString(std::string&& string);
    ~PyString() override = default;

    PyClass *leftAdd(PyClass const &rightElem) const override;

    PyClass *leftMult(PyClass const &rightElem) const override;

    PyClass *leftDiv(PyClass const &rightElem) const override;

    PyClass *leftSub(PyClass const &rightElem) const override;

    PyClass *leftModulu(PyClass const &rightElem) const override;

    PyClass *leftPower(PyClass const &rightElem) const override;

    PyClass *negate() const override;

    PyClass *call(PyClass const &params) override;

    PyBool *leftAnd(PyClass const &rightElem) const override;

    PyBool *leftOr(PyClass const &rightElem) const override;

    PyBool *leftEql(PyClass const &rightElem) const override;

    PyBool *leftBigger(PyClass const &rightElem) const override;

    PyBool *leftSmaller(PyClass const &rightElem) const override;

    PyBool *logicalNot() const override;

    const PyString *asString() const override;

    PyClass *getElem(PyClass const &indexer) const override;

    PyClass *setElem(PyClass const &indexer, PyClass const &newElem) override;

    const std::string& getValue() const;

    PyClass *getSelf() override;

private:
    std::string value;

};


#endif //BASICPYTHONINTERPRETER_PYSTRING_H
