//
// Created by alexey on 14/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_CONTEXT_H
#define BASICPYTHONINTERPRETER_CONTEXT_H


#include <map>
#include "../datatypes/PyObject.h"
#include "Pool.h"

typedef std::string pointer_t;
typedef std::pair<Pool*, PyObject*> objectLoc_t;

class Context {
public:
    std::map<pointer_t, objectLoc_t> pointerTable;
    /**
     * These object don't have a variable name corresponding to them, and they will live as long as the context lives.
     */
    std::vector<PyObject*> anonymousList;

    PyObject* getObject(const pointer_t& ptr);
    const pointer_t* getPtr(const PyObject* obj);

    void addObject(pointer_t& ptr, objectLoc_t& obj);
    void addAnonymousObject(objectLoc_t& obj);

    virtual ~Context() = default;

};


#endif //BASICPYTHONINTERPRETER_CONTEXT_H
