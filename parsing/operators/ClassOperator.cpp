//
// Created by USER on 5/6/2020.
//

#include <ostream>
#include "ClassOperator.h"

Class *ClassOperator::getAsClass() const {
    return val;
}

ClassOperator::ClassOperator(Class * c) : Operator(CLASS), val{c} {}
