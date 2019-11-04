//
// Created by alexey on 03/11/2019.
//

#include "PyBoolean.h"
#include "PyString.h"

AnonymousObject *PyBoolean::addLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::subLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::multLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::divLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyBoolean::asStr() {
    if (value){
        return new AnonymousObject(new PyString("true"));
    } else {
        return new AnonymousObject(new PyString("false"));
    }
}

int PyBoolean::compare(PyObject *other) {
    return -2;
}

bool PyBoolean::equals(PyObject *other) {
    other = other->unmask();
    if (other->getType() != "bool") return false;
    return value == ((PyBoolean*)other)->value;
}

PyBoolean::PyBoolean(bool val) : PyPrimitive("bool"), value(val) {

}
