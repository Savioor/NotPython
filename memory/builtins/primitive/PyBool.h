//
// Created by USER on 5/13/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYBOOL_H
#define BASICPYTHONINTERPRETER_PYBOOL_H


#include "../../PyClass.h"

class PyBool : public PyClass {

public:
    PyBool(bool);

    PyClass *leftAdd(PyClass const &rightElem) const override;

    PyClass *leftMult(PyClass const &rightElem) const override;

    PyClass *leftDiv(PyClass const &rightElem) const override;

    PyClass *leftSub(PyClass const &rightElem) const override;

    PyClass *leftModulu(PyClass const &rightElem) const override;

    PyClass *leftPower(PyClass const &rightElem) const override;

    PyClass *negate() const override;

    PyClass *call(PyClass &params) override;

    PyBool *leftAnd(PyClass const &rightElem) const override;

    PyBool *leftOr(PyClass const &rightElem) const override;

    PyBool *leftEql(PyClass const &rightElem) const override;

    PyBool *leftBigger(PyClass const &rightElem) const override;

    PyBool *leftSmaller(PyClass const &rightElem) const override;

    PyBool *logicalNot() const override;

    const PyString *asString() const override;

    PyClass *getElem(PyClass &indexer) const override;

    PyClass *setElem(PyClass &indexer, PyClass &newElem) override;

    const bool& getValue() const;

    PyClass *getSelf() override;

private:
    bool value;


};


#endif //BASICPYTHONINTERPRETER_PYBOOL_H
