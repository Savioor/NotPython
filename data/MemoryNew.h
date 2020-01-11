//
// Created by alexey on 23/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_MEMORYNEW_H
#define BASICPYTHONINTERPRETER_MEMORYNEW_H


#include "memory-structure/PoolMaster.h"

class MemoryNew {
private:
    MemoryNew();

public:
    PoolMaster mem;

    static MemoryNew& getInstance()
    {
        static MemoryNew instance;
        return instance;
    }

    MemoryNew(MemoryNew const&) = delete;
    void operator=(MemoryNew const&) = delete;

};


#endif //BASICPYTHONINTERPRETER_MEMORYNEW_H
