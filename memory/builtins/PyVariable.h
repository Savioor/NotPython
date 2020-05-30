//
// Created by USER on 5/17/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYVARIABLE_H
#define BASICPYTHONINTERPRETER_PYVARIABLE_H


#include <string>
#include "../PyClass.h"

class PyVariable : public PyClass {

public:
    PyVariable(std::string&&);
    PyVariable(std::string);

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

    PyClass *setSelf(PyClass &other) override;
    const PyClass &getRaw() const override;
    PyClass &getRaw() override;

    const std::string& getName() const;
    const PyClass* getChild() const;
    PyClass* getChild();
    void setChild(PyClass*);
    int myDepth;

private:
    void nullptrTest() const;
    PyClass* child;
    std::string varName;
    bool alloced;

};


#endif //BASICPYTHONINTERPRETER_PYVARIABLE_H
