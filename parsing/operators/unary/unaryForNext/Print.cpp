//
// Created by alexey on 25/05/2020.
//

#include "Print.h"
#include "../../../../memory/builtins/primitive/PyInteger.h"
#include "../../../../memory/MemoryManager.h"
#include <iostream>

PyClass *Print::expand(PyClass *next) {
    std::cout << next->asString()->getValue() << std::endl;
    return MemoryManager::getManager().getNone();
}

Print::Print() {
    precedence = 16; // TODO subject to changes
}
