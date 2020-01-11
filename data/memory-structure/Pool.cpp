//
// Created by alexey on 13/11/2019.
//

#include "Pool.h"
#include "../../optimization.h"
#include <cstdlib>

#if POOL_DEBUG
#include "../IOR.h"
#endif

Pool::~Pool() {
    delete(pool);
    pool = nullptr;
}

Pool::Pool(int8_t blockSize) : blockSize(blockSize), pool((int8_t*)std::malloc(POOL_SIZE)) {
    if (UNLIKELY(blockSize % 8 != 0)){
        throw "What the fuck, block size isn't mod 8";
    }
    type = POOL_AVAILABLE;
    freeBlocksCount = POOL_SIZE / blockSize;
    nextUntouched = pool;
    freeBlocks = new LinkedList<block*>();
}

PyObject *Pool::allocateHere(PyObject &&obj) {
    if (UNLIKELY(freeBlocksCount == 0)){
#if ALLOC_HERE_DEBUG
        IOR::getInstance().reportDebug("No free blocks left in pool, returning null");
#endif
        return nullptr;
    }
    if (UNLIKELY(obj.getMySize() > blockSize)){
#if ALLOC_HERE_DEBUG
        IOR::getInstance().reportDebug("Attempted to allocate object of size " + std::to_string(obj.getMySize()) + " > " +
                                    std::to_string(blockSize));
#endif
        return nullptr;
    }

    PyObject* retPtr;
    if (freeBlocks->empty()){
        // No freed blocks yet
#if ALLOC_HERE_DEBUG
        IOR::getInstance().reportDebug("No free blocks, allocating from nextUntouched. Currently free in this pool = " +
        std::to_string(freeBlocksCount - 1));
#endif
        retPtr = new(nextUntouched) PyObject(obj);
        nextUntouched += blockSize;
    } else {
        // There is a freed block
#if ALLOC_HERE_DEBUG
        IOR::getInstance().reportDebug("There are free blocks, allocating from them. Currently free in this pool = " +
                                       std::to_string(freeBlocksCount - 1));
#endif
        retPtr = new(freeBlocks->getStart()->value) PyObject(obj);
        freeBlocks->disconnectAndKeepAlive(0);
    }

    if (!(--freeBlocksCount)) {
        type = POOL_FULL;
    }

    return retPtr;
}

void Pool::freeResource(PyObject *ptr) {
    auto* asBlock = (block*) ptr;
    if (UNLIKELY(asBlock > pool + POOL_SIZE - blockSize || asBlock < pool)){
#if FREE_DEBUG
        IOR::getInstance().reportDebug("Attempted to free memory outside the jurisdiction of this pool");
#endif
        throw "What";
    }
    if (UNLIKELY(ptr->getType() == Unallocated || (block*)ptr > nextUntouched)){
#if FREE_DEBUG
        IOR::getInstance().reportDebug("Attempted to free memory which is already free, doing nothing");
#endif
        return;
    }
#if FREE_DEBUG
    IOR::getInstance().reportDebug("Freed object. Currently free = " + std::to_string(freeBlocksCount));
#endif
    ptr->getType() = Unallocated;
    freeBlocksCount++;
    type = POOL_AVAILABLE;
    freeBlocks->addToBackV(asBlock);
}

PyObject *Pool::safelyRetrieve(PyObject *obj) {
    auto* asBlock = (block*) obj;
    if (UNLIKELY(asBlock > pool + POOL_SIZE - blockSize || asBlock < pool)){
        return nullptr;
    }
    if (UNLIKELY(obj->getType() == Unallocated)){
        return nullptr;
    }
    return obj;
}

