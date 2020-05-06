//
// Created by alexey on 28/04/2020.
//

#include <ostream>
#include "Operator.h"

Operator::Operator(OPERATOR_TYPE t) : type{t} {

}

Class *Operator::getAsClass() const{
    return nullptr;
}