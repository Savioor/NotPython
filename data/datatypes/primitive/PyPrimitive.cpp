//
// Created by alexey on 01/11/2019.
//

#include "PyPrimitive.h"

PyPrimitive::PyPrimitive(char *name) : PyObject(name){
    isPrimitiveVar = true;
}

PyPrimitive::PyPrimitive(std::string && n) : PyObject(std::move(n)) {
    isPrimitiveVar = true;
}
