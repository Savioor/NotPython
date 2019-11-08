//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"
#include "../../Memory.h"

PyString::PyString() : PyPrimitive("string") {

}

PyString::PyString(char *str) : PyPrimitive("string"), myValue(str) {
}

PyString::PyString(std::string &str) : PyPrimitive("string"), myValue(str) {

}

PyString::PyString(std::string && inp) : PyPrimitive("string"), myValue(inp){
}

AnonymousObject *PyString::addLeft(PyObject *right) {
    right = right->unmask();
    if (right->getType() == "string"){
        return new AnonymousObject(new PyString(this->myValue + ((PyString*)right)->myValue));
    } else {
        // TODO
        return new AnonymousObject(new PyString(this->myValue));
    }
}

AnonymousObject *PyString::subLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyString::multLeft(PyObject *right) {
    return nullptr;
}

AnonymousObject *PyString::divLeft(PyObject *right) {
    return nullptr;
}

std::string PyString::asStr() {
    return this->myValue;
}

int PyString::compare(PyObject *right) {
    return -2;
}

bool PyString::equals(PyObject *other) {
    other = other->unmask();
    if (other->getType() != "string") return false;
    return ((PyString*)other)->myValue == myValue;
}

int PyString::allocCopy() {
    return Memory::getInstance().alloc(new PyString(myValue));
}
