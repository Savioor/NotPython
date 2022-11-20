//
// Created by alexey on 25/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYCODEBLOCK_H
#define BASICPYTHONINTERPRETER_PYCODEBLOCK_H


#include "../PyClass.h"
#include <string>

class PyCodeblock : public PyClass {

public:
    PyCodeblock(std::string&& code);

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

    PyClass* execute();
    PyClass* runAsClassStructure();

	void prefixInnit(const std::string&);

private:
    std::string code;

};


#endif //BASICPYTHONINTERPRETER_PYCODEBLOCK_H
