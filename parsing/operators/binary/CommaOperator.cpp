//
// Created by USER on 5/28/2020.
//

#include "CommaOperator.h"
#include "../../../memory/builtins/PyList.h"

PyClass *CommaOperator::reduce(PyClass *left, PyClass *right) {
    throw std::runtime_error("This shouldn't happen");
    return nullptr;
}

PyClass *CommaOperator::reduceWithBracketContext(PyClass *left, PyClass *right, BRACKET_TYPE leftContext,
                                                 BRACKET_TYPE rightContext) {

    if (left->type == pyARRAY && leftContext == BT_NONE) {

        PyList* asArr = (PyList*)left;
        asArr->pushBack(right);
        return asArr;

    } else {

        PyList* retList = new PyList();
        retList->pushBack(left);
        retList->pushBack(right);
        return retList;

    }

}

CommaOperator::CommaOperator() {

    precedence = 2;

}
