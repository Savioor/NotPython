 //
// Created by USER on 5/22/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYLIST_H
#define BASICPYTHONINTERPRETER_PYLIST_H


#include "../PyClass.h"
#include "functions/PyFunction.h"

 class PyList : public PyClass {

public:
    PyList();
    PyList(int marker);

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

    std::vector<PyClass*>& getElements();

    void pushBack(PyClass*);
    void insertBefore(PyClass*, int);

private:

    std::vector<PyClass*> ls;

};


#endif //BASICPYTHONINTERPRETER_PYLIST_H
