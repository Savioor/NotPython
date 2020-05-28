//
// Created by alexey on 28/04/2020.
//

#include "Operator.h"

Operator::Operator(OPERATOR_TYPE t) : type{t}, bt{BT_NONE} {
    precedence = 0;
}

PyClass *Operator::getAsClass() const{
    return nullptr;
}

int Operator::getPrecedence() {
    return precedence;
}
