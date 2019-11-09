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

class PyObject {

protected:
    std::string type;
    std::map<std::string, int> data;
    bool isPrimitiveVar;
    bool isConstant;

public:
    virtual const std::string& getType() const;
    virtual std::string& getType();

    virtual std::map<std::string, int>& getData();
    virtual const std::map<std::string, int>& getData() const;

    explicit PyObject(std::string&&);
    explicit PyObject(char*);
    PyObject() = delete;

    /**
     *
     * @return The core object, without any primitive wrappers, primitive keeps ownership
     */
    virtual PyObject* unmask();
    /**
     *
     * @return The core object, without any primitive wrappers, primitive doesn't keeps ownership
     */
    virtual PyObject* yoink();

    virtual ~PyObject() = default;

    const bool& isPrimitive();
    const bool& isConst();
    void setConst(bool val);
    PyObject *getVariable(std::string &name);
};


#endif //BASICPYTHONINTERPRETER_PYOBJECT_H
