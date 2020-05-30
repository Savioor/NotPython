//
// Created by alexey on 26/05/2020.
//

#include <stdexcept>
#include "If.h"
#include "../../../../memory/builtins/primitive/PyBool.h"
#include "../../../../memory/builtins/PyCodeblock.h"
#include "../../../../memory/builtins/primitive/PyInteger.h"
#include "../../../../memory/MemoryManager.h"

PyClass *If::reduce(PyClass *right, PyClass *afterRight) {

    if (right->getRaw().type != pyBOOL) {
        throw std::runtime_error("If expected boolean");
    }
    if (afterRight->type != pyCODE_BLOCK) {
        throw std::runtime_error("If expected code block");
    }

    if (((PyBool&)right->getRaw()).getValue()) {
        return ((PyCodeblock*) afterRight)->execute();
    }

    return MemoryManager::getManager().getNone();
}

If::If() {
    precedence = 16;
}
