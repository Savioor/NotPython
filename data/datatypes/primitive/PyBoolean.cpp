//
// Created by alexey on 03/11/2019.
//

#include "PyBoolean.h"
#include "PyString.h"


std::string PyBoolean::asStr() {
    if (value){
        return "true";
    } else {
        return "false";
    }
}

int PyBoolean::compare(objectLoc_t other) {
    return -2;
}

bool PyBoolean::equals(objectLoc_t other) {
    PyObject* otherO = other.first->safelyRetrieve(other.second);
    if (otherO->getType() != Boolean) return false;
    return value == ((PyBoolean*)otherO)->value;
}

PyBoolean::PyBoolean(bool val) : PyPrimitive(Boolean), value(val) {

}

objectLoc_t PyBoolean::addLeft(objectLoc_t right) {
    return {};
}

objectLoc_t PyBoolean::subLeft(objectLoc_t right) {
    return {};
}

objectLoc_t PyBoolean::multLeft(objectLoc_t right) {
    return {};
}

objectLoc_t PyBoolean::divLeft(objectLoc_t right) {
    return {};
}

objectLoc_t PyBoolean::allocCopy() {
    return MemoryNew::getInstance().mem.allocateAnon(PyBoolean(value));
}
