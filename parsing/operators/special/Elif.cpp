//
// Created by USER on 6/5/2020.
//

#include "Elif.h"
#include "../OptionalCodeblock.h"

Operator *Elif::reduce(std::shared_ptr<Operator> before, std::shared_ptr<Operator> after, std::shared_ptr<Operator> secondAfter) {
    if (after->bt != BT_ROUND) {
        throw std::runtime_error("elif expected round bracket expression");
    }

    PyClass* afterRightClass = secondAfter->getAsClass();
    if (afterRightClass == nullptr || afterRightClass->type != pyCODE_BLOCK) {
        throw std::runtime_error("elif expected code block");
    }

    if (before->type != OPTIONAL_CODEBLOCK) {
        throw std::runtime_error("elif expected to be after and if\\elif");
    }

    return new OptionalCodeblock((PyCodeblock*)afterRightClass,
                                 std::static_pointer_cast<OptionalCodeblock>(before),
                                 std::static_pointer_cast<RoundBrackets>(after));

}

Elif::Elif() {
    precedence = 16;
}
