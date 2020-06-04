//
// Created by alexey on 31/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYMETHOD_H
#define BASICPYTHONINTERPRETER_PYMETHOD_H


#include "../functions/PyFunction.h"
#include "PyClassInstance.h"

class PyMethod : public PyClass {

public:
    PyMethod(PyFunction*, PyClass*);

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

    PyClass *getElem(PyClass &indexer) const override;

    PyClass *setElem(PyClass &indexer, PyClass &newElem) override;

private:
    PyFunction* wrappedFunction;
    PyClass* methodOwner;

};


#endif //BASICPYTHONINTERPRETER_PYMETHOD_H
