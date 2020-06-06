//
// Created by alexey on 26/05/2020.
//

#include <stdexcept>
#include "If.h"
#include "../../../../memory/builtins/primitive/PyBool.h"
#include "../../../../memory/builtins/PyCodeblock.h"
#include "../../../../memory/builtins/primitive/PyInteger.h"
#include "../../OptionalCodeblock.h"

Operator *If::reduceWithFullContext(std::shared_ptr<Operator>& right, std::shared_ptr<Operator>& afterRight) {

    if (right->bt != BT_ROUND) {
        throw std::runtime_error("If expected round bracket expression");
    }

    PyClass* afterRightClass = afterRight->getAsClass();
    if (afterRightClass == nullptr || afterRightClass->type != pyCODE_BLOCK) {
        throw std::runtime_error("If expected code block");
    }

    return new OptionalCodeblock((PyCodeblock*)afterRightClass, nullptr, std::static_pointer_cast<RoundBrackets>(right));

}

If::If() {
    precedence = 16;
}

Operator *If::reduce(PyClass *right, PyClass *afterRight) {
    return nullptr;
}
