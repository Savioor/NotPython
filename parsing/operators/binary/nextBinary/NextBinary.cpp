//
// Created by alexey on 26/05/2020.
//

#include "NextBinary.h"

NextBinary::NextBinary() : Operator(BINARY_BOTH_AFTER) {

}

Operator *NextBinary::reduceWithFullContext(std::shared_ptr<Operator>& right, std::shared_ptr<Operator>& afterRight) {
    PyClass* lClass = right->getAsClass();
    PyClass* rClass = afterRight->getAsClass();

    if (lClass == nullptr || rClass == nullptr) {
        throw std::runtime_error("right or after right operator of bin operator aren't classes.");
    }

    return reduce(lClass, rClass);
}
