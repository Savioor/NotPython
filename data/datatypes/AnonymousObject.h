//
// Created by alexey on 28/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_ANONYMOUSOBJECT_H
#define BASICPYTHONINTERPRETER_ANONYMOUSOBJECT_H


#include "PyObject.h"

class AnonymousObject : public PyObject {
private:
    PyObject* obj;

#if OBJECT_DEBUG == true
    static int anonCount;
#endif

public:

    AnonymousObject();
    AnonymousObject(PyObject*);
    PyObject* releaseObject();
    PyObject* getObject();

    virtual ~AnonymousObject();

    virtual std::map<std::string, int> &getData() override ;

    virtual const std::map<std::string, int> &getData() const override ;
};

#endif //BASICPYTHONINTERPRETER_ANONYMOUSOBJECT_H
