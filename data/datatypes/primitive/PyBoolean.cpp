//
// Created by alexey on 03/11/2019.
//

#include "PyBoolean.h"
#include "PyString.h"
#include "../../Memory.h"

AnonymousObject *PyBoolean::addLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::subLeft(PyObject *right) {
    return nullptr;
}
bool
AnonymousObject *PyBoolean::multLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::divLeft(PyObject *right) {
    return nullptr;
}

std::string PyBoolean::asStr() {
    if (value){
        return "true";
    } else {
        return "false";
    }
}

int PyBoolean::compare(PyObject *other) {
    return -2;
}

bool PyBoolean::equals(PyObject *other) {
    if (other->getType() != Boolean) return false;
    return value == ((PyBoolean*)other)->value;
}

PyBoolean::PyBoolean(bool val) : PyPrimitive("bool"), value(val) {

}


int PyBoolean::allocCopy() {
    return Memory::getInstance().alloc(new PyBoolean(value));
}
