//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYOBJECT_H
#define BASICPYTHONINTERPRETER_PYOBJECT_H

#include <string>
#include <array>
#include <map>
#include <vector>
#include "../../debug.h"

enum EType {
    Unallocated, // = 0 = nullptr
    Integer,
    String,
    Boolean,
    Function,
    BinaryOperator,
    UnaryOperatorLeft,
    UnaryOperatorRight,
    Rvalue,
    Class
};

class PyObject {

protected:
    EType type;
    std::map<std::string, PyObject*> data;
    bool isConstant;

public:
    virtual EType& getType();

    virtual std::map<std::string, PyObject*>& getData();
    virtual const std::map<std::string, PyObject*>& getData() const;

    virtual size_t getMySize();

    explicit PyObject(EType t);
    PyObject() = delete;

    virtual ~PyObject() = default;

    inline const bool isPrimitive() {
        return type != Class;
    };
    const bool& isConst();
    void setConst(bool val);
    PyObject *getVariable(std::string &name);
};


#endif //BASICPYTHONINTERPRETER_PYOBJECT_H
