//
// Created by alexey on 26/05/2020.
//

#include <stdexcept>
#include "If.h"
#include "../../../../memory/builtins/PyBool.h"
#include "../../../../memory/builtins/PyCodeblock.h"
#include "../../../../memory/builtins/PyInteger.h"

PyClass *If::reduce(PyClass *right, PyClass *afterRight) {

    if (right->type != pyBOOL) {
        throw std::runtime_error("If expected boolean");
    }
    if (afterRight->type != pyCODE_BLOCK) {
        throw std::runtime_error("If expected code block");
    }

    if (((PyBool*)right)->getValue()) {
        return ((PyCodeblock*) afterRight)->execute();
    }

    return new PyInteger(1); // TODO replace with None
}

If::If() {
    precedence = 16;
}
