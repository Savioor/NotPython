//
// Created by alexey on 17/04/2020.
//

#include "BinaryOperator.h"

BinaryOperator::BinaryOperator() : Operator(BINARY) {

}

PyClass *BinaryOperator::reduceWithBracketContext(PyClass *left, PyClass *right, BRACKET_TYPE leftContext,
                                                  BRACKET_TYPE rightContext) {
    return reduce(left, right);
}

PyClass *BinaryOperator::reduceWithFullContext(Operator *left, Operator *right) {
    PyClass* lClass = left->getAsClass();
    PyClass* rClass = right->getAsClass();

    if (lClass == nullptr || rClass == nullptr) {
        throw std::runtime_error("Right or left operand of binary expression are not classes.");
    }

    return reduceWithBracketContext(lClass, rClass, left->bt, right->bt);

}

