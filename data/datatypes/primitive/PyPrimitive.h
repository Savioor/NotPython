//
// Created by alexey on 01/11/2019.
//

#ifndef BASICPYTHONINTERPRETER_PYPRIMITIVE_H
#define BASICPYTHONINTERPRETER_PYPRIMITIVE_H


#include "../PyObject.h"
#include "../../memory-structure/PoolMaster.h"
#include "../../MemoryNew.h"
#include <string>

#define ALLOC_ANON(obj) MemoryNew::getInstance().mem.allocateAnon(obj)

class PyPrimitive : public PyObject {
public:
    explicit PyPrimitive(EType);
    PyPrimitive() = delete;

    virtual ~PyPrimitive() = default;

    /**
     * All of these functions assume they receive a VALID input. A valid input is any object that is allocated in
     * memory. Even if an operation can't be preformed with that object (say inputing a bool object to an int addition
     * function) the input is still considered VALID.
     * when an input is INVALID, i.e. not an actual object in memory, a NullPointerException will be thrown. This
     * shouldn't happen ever. If it happens it's a BUG.
     * If the input is valid but the operation is impossible with the given input types {nullptr, nullptr} will be
     * returned. This is OK and it is the responsibility of the caller to deal with this.
     */

    virtual objectLoc_t addLeft(objectLoc_t right) = 0;
    virtual objectLoc_t subLeft(objectLoc_t right) = 0;
    virtual objectLoc_t multLeft(objectLoc_t right) = 0;
    virtual objectLoc_t divLeft(objectLoc_t right) = 0;

    virtual std::string asStr() = 0;
    virtual objectLoc_t allocCopy() = 0;

    /**
     *
     * @param other
     * @return 1 if I am bigger, -1 if I am smaller, 0 if I am equal.
     */
    virtual int compare(objectLoc_t other) = 0;

    virtual bool equals(objectLoc_t other) = 0;
};


#endif //BASICPYTHONINTERPRETER_PYPRIMITIVE_H
