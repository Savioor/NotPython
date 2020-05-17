//
// Created by USER on 5/17/2020.
//

#include "SetOperator.h"

PyClass *SetOperator::reduce(PyClass *left, PyClass *right) {
    left->setSelf(*right);
    return left;
}

SetOperator::SetOperator() {
    precedence = 1;
}
