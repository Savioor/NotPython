//
// Created by USER on 5/7/2020.
//

#include "SimpleBinaryOperator.h"


SimpleBinaryOperator::SimpleBinaryOperator(int pred, Class* (*op)(Class*, Class*)) : BinaryOperator(), operation{op} {
    precedence = pred;
}

Class *SimpleBinaryOperator::reduce(Class *left, Class *right) {
    return (*operation)(left, right);
}
