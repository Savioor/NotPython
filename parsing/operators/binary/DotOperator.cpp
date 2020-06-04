//
// Created by alexey on 31/05/2020.
//

#include "DotOperator.h"
#include "../../../memory/builtins/PyVariable.h"

PyClass *DotOperator::reduce(PyClass *left, PyClass *right) {
    if (right->type != pyVAR) {
        throw std::runtime_error("Dot operator expected pyVAR as second input");
    }
    PyClass* expandedLeft = &left->getRaw();
    PyVariable* asVar = (PyVariable*) right;
    if (expandedLeft->pointerMap.count(asVar->getName()) == 0) {
        expandedLeft->pointerMap.insert({asVar->getName(), new PyVariable(asVar->getName(), false)});
    }
    return expandedLeft->pointerMap[asVar->getName()];
}

DotOperator::DotOperator() {
    precedence = 16;
}
