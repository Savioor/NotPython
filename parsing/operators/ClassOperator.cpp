//
// Created by USER on 5/6/2020.
//

#include <ostream>
#include "ClassOperator.h"

PyClass *ClassOperator::getAsClass() const {
    return val;
}

ClassOperator::ClassOperator(PyClass * c) : Operator(CLASS), val{c} {}
