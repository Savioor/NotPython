//
// Created by alexey on 14/11/2019.
//

#include "Context.h"
#include "../../optimization.h"

objectLoc_t Context::getObject(const pointer_t &ptr) {
    auto val = pointerTable.find(ptr);
    if (UNLIKELY(val == pointerTable.end())) return nullptr;
    return (*val).second;
}

const pointer_t *Context::getPtr(const PyObject *obj) {
    for (const auto& iter : pointerTable){
        if (iter.second.second == obj)
            return &(iter.first);
    }
    return nullptr;
}


void Context::addObject(pointer_t& ptr, objectLoc_t& obj) {
    pointerTable.insert({ptr, obj});
}

void Context::addAnonymousObject(objectLoc_t &obj) {
    anonymousList.push_back(obj.second);
}
