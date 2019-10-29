//
// Created by alexey on 24/10/2019.
//

#include "PyString.h"

PyString::PyString() : PyObject("string") {

}

PyString::PyString(char *str) : PyObject("string"), myValue(str) {

}

PyString::PyString(std::string &str) : PyObject("string"), myValue(str) {

}

PyString::PyString(std::string && inp) : PyObject("string"), myValue(inp){
}

AnonymousObject *PyString::leftAdd(PyObject *right) {
    right = right->unmask();
    if (right->getType() == "string"){
        return new AnonymousObject(new PyString(this->myValue + ((PyString*)right)->myValue));
    } else {
        // TODO
        return new AnonymousObject(new PyString(this->myValue));
    }
}
