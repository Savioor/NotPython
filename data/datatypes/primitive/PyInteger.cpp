//
// Created by alexey on 06/11/2019.
//

#include "PyInteger.h"
#include "PyString.h"
#include <sstream>

PyInteger::PyInteger() : PyPrimitive("int") {

}

PyInteger::PyInteger(long i) : PyPrimitive("int"), myValue(i) {

}

AnonymousObject *PyInteger::addLeft(PyObject *right) {
    right = right->unmask();
    if (right->getType() != "int"){
        throw "TODO this";
        return nullptr;
    }
    auto* asInt = (PyInteger*)right;
    return new AnonymousObject(new PyInteger(myValue + asInt->myValue));
}

AnonymousObject *PyInteger::subLeft(PyObject *right) {
    right = right->unmask();
    if (right->getType() != "int"){
        throw "TODO this";
        return nullptr;
    }
    auto* asInt = (PyInteger*)right;
    return new AnonymousObject(new PyInteger(myValue - asInt->myValue));}

AnonymousObject *PyInteger::multLeft(PyObject *right) {
    right = right->unmask();
    if (right->getType() != "int"){
        throw "TODO this";
        return nullptr;
    }
    auto* asInt = (PyInteger*)right;
    return new AnonymousObject(new PyInteger(myValue * asInt->myValue));}

AnonymousObject *PyInteger::divLeft(PyObject *right) {
    right = right->unmask();
    if (right->getType() != "int"){
        throw "TODO this";
        return nullptr;
    }
    auto* asInt = (PyInteger*)right;
    return new AnonymousObject(new PyInteger(myValue / asInt->myValue));}

std::string PyInteger::asStr() {
    std::stringstream stream;
    stream << myValue;
    std::string myStr;
    stream >> myStr;
    return std::move(myStr);
}

int PyInteger::allocCopy() {
    return 0;
}

int PyInteger::compare(PyObject *right) {
    return 0;
}

bool PyInteger::equals(PyObject *other) {
    other = other->unmask();
    if (other->getType() != "int"){
        return false;
    }
    auto* asInt = (PyInteger*)other;
    return myValue == asInt->myValue;
}
