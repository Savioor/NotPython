//
// Created by alexey on 14/11/2019.
//

#include "PoolMaster.h"

pointerValuePair_t PoolMaster::getObject(pointer_t &ptr) {
    pointerValuePair_t retPair{ptr, nullptr};
    for (auto iter = --contextList.end(); iter != contextList.begin(); iter--){
        retPair.second = (*iter.base())->getObject(ptr);
        if (retPair.second != nullptr) return retPair;
    }
    return retPair;
}

pointer_t PoolMaster::allocate(pointer_t& ptr, PyObject &&obj) {
    objectLoc_t&& loc = allocateAnon(std::move(obj));
    contextList.at(contextList.size() - 1)->addObject(ptr, loc);
    return ptr;
}

objectLoc_t PoolMaster::allocateAnon(PyObject &&obj) {
//    size_t objSize = obj.getMySize();

    // Step one, look for matching pool
    // TODO actually have pools of different sizes, the following is temporary code
    Pool* allocPool;
    PyObject* objectLoc;

    if (freePools.empty()){
        // No pools exists
        allocPool = new Pool( 64);
        freePools.addToFrontV(allocPool);
        objectLoc = allocPool->allocateHere(std::move(obj));
    } else {
        allocPool = freePools.getStart()->value;
        objectLoc = allocPool->allocateHere(std::move(obj));
        if (allocPool->isFull()){
            freePools.disconnectAndKeepAlive(0);
            fullPools.addToFrontV(allocPool);
        }
    }
    return {allocPool, objectLoc};
}

PoolMaster::PoolMaster() : contextList() {
    // First context is global context
    contextList.push_back(new Context());
}

PoolMaster::~PoolMaster() {
    for (auto& c : contextList){
        delete(c);
        c = nullptr;
    }
    // TODO delete other things
}
