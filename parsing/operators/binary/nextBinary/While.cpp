//
// Created by USER on 5/30/2020.
//

#include "While.h"
#include "../../encapsulating/SquareBrackets.h"
#include "../../../../memory/builtins/PyCodeblock.h"
#include "../../../../memory/builtins/primitive/PyBool.h"
#include "../../../../memory/MemoryManager.h"


PyClass *While::reduce(PyClass *right, PyClass *afterRight) {
    throw std::runtime_error("This should happen");
    return nullptr;
}

PyClass *While::reduceWithFullContext(Operator *right, Operator *afterRight) {

    if (right->bt != BT_ROUND) {
        throw std::runtime_error("while loop expected round brackets!");
    }
    PyClass* code = afterRight->getAsClass();

    if (code == nullptr || code->type != pyCODE_BLOCK) {
        throw std::runtime_error("while loop expected code block");
    }
    PyCodeblock* asCB = (PyCodeblock*) code;

    SquareBrackets* expr = (SquareBrackets*) right;


    while (true) {

        PyClass* exprRes = &expr->getAsClass()->getRaw();
        if (exprRes->type != pyBOOL) {
            throw std::runtime_error("Expression in while loops expected boolean");
        }
        if (!((PyBool*)exprRes)->getValue()) {
            break;
        }

        PyClass* cbResult = asCB->execute();
        if (cbResult->isReturnValue) {
            return cbResult;
        }

    }

    return MemoryManager::getManager().getNone();
}

While::While() {
    precedence = 16;
}
