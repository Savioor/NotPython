//
// Created by alexey on 17/04/2020.
//

#ifndef BASICPYTHONINTERPRETER_PYCLASS_H
#define BASICPYTHONINTERPRETER_PYCLASS_H

#define static_ver_bin_decl_deep(name, type) static type* name(PyClass* leftElem, PyClass* rightElem)
#define static_ver_bin_decl(name) static_ver_bin_decl_deep(name, PyClass)

#define static_ver_bin_impl_deep(name, func, type) type *PyClass::name(PyClass *leftElem, PyClass *rightElem) { return leftElem->func(*rightElem); }
#define static_ver_bin_impl(name, func) static_ver_bin_impl_deep(name, func, PyClass)



#include <vector>

class PyBool;
class PyString;

enum BuiltInClasses {
    pyINTEGER,
    pyBOOL,
    pyFUNCTION,
    pyDOUBLE,
    pySTRING,
    pyARRAY,
    pyVAR,
    pyOTHER
};

class PyClass {

public:

    PyClass();
    virtual ~PyClass() = default;

    int references;
    int expressionDepth;
    int memoryAllocationLocation;
    BuiltInClasses type;

    // Mathematical operations
    virtual PyClass* leftAdd(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(add);
    virtual PyClass* leftMult(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(mult);
    virtual PyClass* leftDiv(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(div);
    virtual PyClass* leftSub(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(sub);

    // Slightly weird mathematical operations
    virtual PyClass* leftModulu(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(mod);
    virtual PyClass* leftPower(PyClass const& rightElem) const = 0;
    static_ver_bin_decl(pow);
    virtual PyClass* negate() const = 0;

    // Logical operators
    virtual PyBool* leftAnd(PyClass const& rightElem) const = 0;
    static_ver_bin_decl_deep(pyAnd, PyBool);
    virtual PyBool* leftOr(PyClass const& rightElem) const = 0;
    static_ver_bin_decl_deep(pyOr, PyBool);
    virtual PyBool* leftEql(PyClass const& rightElem) const = 0;
    static_ver_bin_decl_deep(eql, PyBool);
    virtual PyBool* leftBigger(PyClass const& rightElem) const = 0;
    static_ver_bin_decl_deep(bigger, PyBool);
    virtual PyBool* leftSmaller(PyClass const& rightElem) const = 0;
    static_ver_bin_decl_deep(smaller, PyBool);

    virtual PyBool* logicalNot() const = 0;

    // TODO This should receive List const& when they exist
    virtual PyClass* call(PyClass const& params) = 0;

    virtual const PyString* asString() const = 0;

    // Array Operations
    // TODO this is kinda maybe a bad idea,
    // TODO but I'll cross that bridge when I get to it
    virtual PyClass* getElem(PyClass const& indexer) const = 0;
    virtual PyClass* setElem(PyClass const& indexer,
                           PyClass const& newElem) = 0;

    // Literally just for the `=` operation
    virtual PyClass* setSelf(PyClass& other);

    // Returns itself if PyOTHER, child if PyVAR, and copy of itself otherwise
    virtual PyClass* getSelf();

};


#endif //BASICPYTHONINTERPRETER_PYCLASS_H
