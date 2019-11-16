//
// Created by alexey on 14/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_POOLMASTER_H
#define BASICPYTHONINTERPRETER_POOLMASTER_H


#include "../../util/LinkedList.h"
#include "Pool.h"
#include "Context.h"

typedef std::string pointer_t;
typedef std::pair<Pool*, PyObject*> objectLoc_t;

typedef std::pair<pointer_t&, PyObject*> pointerValuePair_t;

class PoolMaster {

protected:
    LinkedList<Pool*> freePools;
    LinkedList<Pool*> fullPools;

    std::map<pointer_t, objectLoc_t> globalPointerTable;
    std::vector<Context*> contextList;

public:

    pointerValuePair_t getObject(pointer_t& ptr);
    pointer_t allocate(pointer_t& ptr, PyObject&& obj);
    objectLoc_t allocateAnon(PyObject&& obj);

};


#endif //BASICPYTHONINTERPRETER_POOLMASTER_H
