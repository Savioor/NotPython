//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"
#include "../../Memory.h"

PyString::PyString() : PyPrimitive(String) {

}

PyString::PyString(char *str) : PyPrimitive(String), myValue(str) {
}

PyString::PyString(std::string &str) : PyPrimitive(String), myValue(str) {

}

PyString::PyString(std::string && inp) : PyPrimitive(String), myValue(inp){
}

PyObject *PyString::addLeft(PyObject *right) {
    if (right->getType() == String){
        return new PyString(this->myValue + ((PyString*)right)->myValue);
    } else {
        // TODO
        return new PyString(this->myValue);
    }
}

PyObject *PyString::subLeft(PyObject *right) {
    return nullptr;
}

PyObject *PyString::multLeft(PyObject *right) {
    return nullptr;
}

PyObject *PyString::divLeft(PyObject *right) {
    return nullptr;
}

std::string PyString::asStr() {
    return this->myValue;
}

int PyString::compare(PyObject *right) {
    return -2;
}

bool PyString::equals(PyObject *other) {
    if (other->getType() != String) return false;
    return ((PyString*)other)->myValue == myValue;
}

int PyString::allocCopy() {
    return Memory::getInstance().alloc(new PyString(myValue));
}
