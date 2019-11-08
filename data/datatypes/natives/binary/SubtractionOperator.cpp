//
// Created by alexey on 08/11/2019.
//

#include "SubtractionOperator.h"
#include "../../primitive/PyPrimitive.h"

SubtractionOperator::SubtractionOperator() : BinaryNativeFunction("-") {

}

PyObject *SubtractionOperator::execute(PyObject *left, PyObject *right) {
    left = left->unmask();
    right = right->unmask();

    if (left->isPrimitive()){
        return ((PyPrimitive*)left)->subLeft(right);
    }

    throw "Write this code you dumbfuck";

    return nullptr;
}
