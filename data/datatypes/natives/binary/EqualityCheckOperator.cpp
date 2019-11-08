//
// Created by alexey on 06/11/2019.
//

#include "EqualityCheckOperator.h"
#include "../../primitive/PyPrimitive.h"
#include "../../primitive/PyBoolean.h"

EqualityCheckOperator::EqualityCheckOperator() : BinaryNativeFunction("==") {

}

PyObject *EqualityCheckOperator::execute(PyObject *left, PyObject *right) {
    left = left->unmask();
    right = right->unmask();

    if (left->isPrimitive()){
        return new AnonymousObject(new PyBoolean(((PyPrimitive*)left)->equals(right)));
    }

    // TODO implement for non primitives
    throw "Write this code you dumbfuck";

    return nullptr;
}
