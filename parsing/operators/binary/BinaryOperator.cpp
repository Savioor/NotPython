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

