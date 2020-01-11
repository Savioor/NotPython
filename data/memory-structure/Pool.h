//
// Created by alexey on 13/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_POOL_H
#define BASICPYTHONINTERPRETER_POOL_H


#include "../datatypes/PyObject.h"
#include "../../util/LinkedList.h"
#include "PoolMaster.h"

#define POOL_SIZE 1024 * 4

#define POOL_AVAILABLE 1
#define POOL_FULL 2

#define get(item) item.first->safelyRetrieve(item.second);

typedef int8_t block;

class Pool {
protected:
    int8_t type;
    int32_t freeBlocksCount;

    block* nextUntouched;
    block* pool;
    LinkedList<block*>* freeBlocks;

    // Not sure this is useful
//    LinkedList<block*>* usedBlocks;

public:

    Pool(int8_t blockSize);
    virtual ~Pool();

    const int8_t blockSize;

    PyObject* allocateHere(PyObject&& obj);
    void replaceMemory(objectLoc_t source, objectLoc_t destination);
    void freeResource(PyObject* ptr);
    PyObject* safelyRetrieve(PyObject* obj);

    inline const int32_t& getFreeBlockCount(){
        return freeBlocksCount;
    }
    inline const int8_t& getType() {
        return type;
    };

    inline bool isFull(){
        return type == POOL_FULL;
    }
    inline bool isAvailable(){
        return type == POOL_AVAILABLE;
    }

};


#endif //BASICPYTHONINTERPRETER_POOL_H
