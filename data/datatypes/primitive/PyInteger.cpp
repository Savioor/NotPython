//
// Created by alexey on 06/11/2019.
//

#include "PyInteger.h"
#include "PyString.h"
#include <sstream>

PyInteger::PyInteger() : PyPrimitive(Integer) {

}

PyInteger::PyInteger(long i) : PyPrimitive(Integer), myValue(i) {

}

objectLoc_t PyInteger::addLeft(objectLoc_t right) {
    PyObject* rightObject = PoolMaster::retrieve(right);
    if (UNLIKELY(rightObject == nullptr))
        return {nullptr, nullptr};
    if (rightObject->getType() != Integer){
        throw "TODO this";
        return {nullptr, nullptr};
    }
    auto* asInt = (PyInteger*)rightObject;
    return ALLOC_ANON(PyInteger(myValue + asInt->myValue));
}

objectLoc_t PyInteger::subLeft(objectLoc_t right) {
    PyObject *rightObject = PoolMaster::retrieve(right);
    if (UNLIKELY(rightObject == nullptr))
        return {nullptr, nullptr};
    if (rightObject->getType() != Integer) {
        throw "TODO this";
        return {nullptr, nullptr};
    }
    auto *asInt = (PyInteger *) rightObject;
    return ALLOC_ANON(PyInteger(myValue - asInt->myValue));
}

objectLoc_t PyInteger::multLeft(objectLoc_t right) {
    PyObject* rightObject = PoolMaster::retrieve(right);
    if (UNLIKELY(rightObject == nullptr))
        return {nullptr, nullptr};
    if (rightObject->getType() != Integer){
        throw "TODO this";
        return {nullptr, nullptr};
    }
    auto* asInt = (PyInteger*)rightObject;
    return ALLOC_ANON(PyInteger(myValue * asInt->myValue));
}

objectLoc_t PyInteger::divLeft(objectLoc_t right) {
    PyObject* rightObject = PoolMaster::retrieve(right);
    if (UNLIKELY(rightObject == nullptr))
        return {nullptr, nullptr};
    if (rightObject->getType() != Integer){
        throw "TODO this";
        return {nullptr, nullptr};
    }
    auto* asInt = (PyInteger*)rightObject;
    return ALLOC_ANON(PyInteger(myValue / asInt->myValue));
}

std::string PyInteger::asStr() {
    static std::stringstream stream;
    stream << myValue;
    std::string myStr;
    stream >> myStr;
    return std::move(myStr);
}

objectLoc_t PyInteger::allocCopy() {
    return {nullptr, nullptr};
}

int PyInteger::compare(objectLoc_t right) {
    return 0;
}

bool PyInteger::equals(objectLoc_t other) {
    PyObject* o = other.first->safelyRetrieve(other.second);
    if (o->getType() != Integer){
        return false;
    }
    auto* asInt = (PyInteger*)o;
    return myValue == asInt->myValue;
}
