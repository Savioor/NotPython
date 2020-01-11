//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"
#include "../../MemoryNew.h"
#include "../../../util/NullPointerException.h"

PyString::PyString() : PyPrimitive(String) {

}

PyString::PyString(char *str) : PyPrimitive(String), myValue(str) {
}

PyString::PyString(std::string &str) : PyPrimitive(String), myValue(str) {

}

PyString::PyString(std::string && inp) : PyPrimitive(String), myValue(inp){
}

objectLoc_t PyString::addLeft(objectLoc_t right) {
    PyObject* rightObj = PoolMaster::retrieve(right);
    if (UNLIKELY(rightObj == nullptr)) {
        throw NullPointerException();
    }

    if (rightObj->getType() == String){
        return ALLOC_ANON(PyString(this->myValue + ((PyString*)rightObj)->myValue));
    } else {
        // TODO
        return ALLOC_ANON(PyString(this->myValue));
    }
}

objectLoc_t PyString::subLeft(objectLoc_t right) {
    return {nullptr, nullptr};
}

objectLoc_t PyString::multLeft(objectLoc_t right) {
    return {nullptr, nullptr};
}

objectLoc_t PyString::divLeft(objectLoc_t right) {
    return {nullptr, nullptr};
}

std::string PyString::asStr() {
    return this->myValue;
}

int PyString::compare(objectLoc_t right) {
    return -2;
}

bool PyString::equals(objectLoc_t other) {
    PyObject* otherObj = PoolMaster::retrieve(other);
    if (otherObj->getType() != String) return false;
    return ((PyString*)otherObj)->myValue == myValue;
}

objectLoc_t PyString::allocCopy() {
    return MemoryNew::getInstance().mem.allocateAnon(PyString(myValue));
}
