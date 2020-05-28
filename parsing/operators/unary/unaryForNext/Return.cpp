//
// Created by USER on 5/28/2020.
//

#include "Return.h"

PyClass *Return::expand(PyClass *next) {
    PyClass* raw = &(next->getRaw());
    raw->isReturnValue = true;
    return raw;
}

Return::Return() {
    precedence = 0;
}
