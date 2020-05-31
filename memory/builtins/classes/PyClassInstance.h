//
// Created by alexey on 31/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYCLASSINSTANCE_H
#define BASICPYTHONINTERPRETER_PYCLASSINSTANCE_H


#include "../../PyClass.h"
#include "PyClassStructure.h"
#include "../PyFunction.h"

class PyClassInstance : public PyClass {

public:
    PyClassInstance(PyClassStructure*);

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

    PyClassStructure* type;

};


#endif //BASICPYTHONINTERPRETER_PYCLASSINSTANCE_H
