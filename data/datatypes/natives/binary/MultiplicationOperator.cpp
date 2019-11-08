//
// Created by alexey on 08/11/2019.
//

#include "MultiplicationOperator.h"
#include "../../primitive/PyPrimitive.h"

MultiplicationOperator::MultiplicationOperator() : BinaryNativeFunction("*") {
}

PyObject *MultiplicationOperator::execute(PyObject *left, PyObject *right) {
    left = left->unmask();
    right = right->unmask();

    if (left->isPrimitive()){
        return ((PyPrimitive*)left)->multLeft(right);
    }

    throw "Write this code you dumbfuck";

    return nullptr;
}
