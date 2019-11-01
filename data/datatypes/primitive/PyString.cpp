//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"

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

AnonymousObject *PyString::asStr(PyObject *right) {
    return new AnonymousObject(new PyString(this->myValue));
}
