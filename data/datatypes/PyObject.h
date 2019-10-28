//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYOBJECT_H
#define BASICPYTHONINTERPRETER_PYOBJECT_H

#include <string>
#include <array>
#include <map>
#include <vector>

class PyObject {

protected:
    std::string type;
    std::map<std::string, int> data;

public:
    virtual const std::string& getType() const;
    virtual std::map<std::string, int>& getData();
    virtual const std::map<std::string, int>& getData() const;

    explicit PyObject(std::string&&);
    explicit PyObject(char*);
    PyObject() = delete;

    virtual ~PyObject() = default;

    PyObject *getVariable(std::string &name);
};


#endif //BASICPYTHONINTERPRETER_PYOBJECT_H
