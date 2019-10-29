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

    if (left->getType() == "string"){
        return ((PyString*)left)->leftAdd(right);
    }
    return nullptr;
}
