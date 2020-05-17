//
// Created by USER on 5/7/2020.
//

#include "SimpleBinaryOperator.h"


SimpleBinaryOperator::SimpleBinaryOperator(int pred, PyClass* (*op)(PyClass*, PyClass*)) : BinaryOperator(), operation{op} {
    precedence = pred;
}

PyClass *SimpleBinaryOperator::reduce(PyClass *left, PyClass *right) {
    return (*operation)(left, right);
}
