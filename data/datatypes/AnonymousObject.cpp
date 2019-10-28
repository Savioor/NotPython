//
// Created by alexey on 28/10/2019.
//

#include "AnonymousObject.h"

AnonymousObject::AnonymousObject() : PyObject("rvalue") {

}

PyObject *AnonymousObject::getObj() {
    auto* temp = obj;
    obj = nullptr;
    return temp;
}

AnonymousObject::~AnonymousObject() {
    if (obj != nullptr)
        delete(obj);
}

std::map<std::string, int> &AnonymousObject::getData() {
    return obj->getData();
}

const std::map<std::string, int> &AnonymousObject::getData() const {
    return obj->getData();
}

AnonymousObject::AnonymousObject(PyObject *o) : PyObject("rvalue"), obj(o) {

}
