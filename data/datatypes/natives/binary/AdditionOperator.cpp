//
// Created by alexey on 29/10/2019.
//

#include "AdditionOperator.h"
#include "../../primitive/PyString.h"

AdditionOperator::AdditionOperator() : BinaryNativeFunction("+") {

}

PyObject *AdditionOperator::execute(PyObject *left, PyObject *right) {
    left = left->unmask();
    right = right->unmask();

    if (left->isPrimitive()){
        return ((PyPrimitive*)left)->addLeft(right);
    }
    return nullptr;
}
