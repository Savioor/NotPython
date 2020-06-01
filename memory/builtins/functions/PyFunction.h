//
// Created by USER on 5/28/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYFUNCTION_H
#define BASICPYTHONINTERPRETER_PYFUNCTION_H


#include "../../PyClass.h"
#include "../PyCodeblock.h"
#include "../PyList.h"

class PyFunction : public PyClass {

public:
    PyFunction(PyClass*, PyCodeblock*);

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

    PyClass *call(PyClass &params) override;

    const PyString *asString() const override;

    PyClass *getElem(PyClass const &indexer) const override;

    PyClass *setElem(PyClass const &indexer, PyClass const &newElem) override;

};


#endif //BASICPYTHONINTERPRETER_PYFUNCTION_H
