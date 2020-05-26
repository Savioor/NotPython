//
// Created by alexey on 25/05/2020.
//

#include "Print.h"
#include "../../../../memory/builtins/PyInteger.h"
#include <iostream>

PyClass *Print::expand(PyClass *next) {
    std::cout << next->asString()->getValue() << std::endl;
    return new PyInteger(1); // TODO placeholder for None
}

Print::Print() {
    precedence = 16; // TODO subject to changes
}
