//
// Created by USER on 5/28/2020.
//

#include "Def.h"
#include "../../../memory/MemoryManager.h"
#include "../../../memory/builtins/PyFunction.h"

PyClass *Def::reduce(PyClass *first, PyClass *second, PyClass *third) {

    if (first->type != pyVAR ||
    (second->type != pyARRAY && second->type != pyVAR && second != MemoryManager::getManager().getNone()) ||
    third->type != pyCODE_BLOCK) {
        throw std::runtime_error("Attempting to define function with illeagal operators");
    }
    PyFunction* func = new PyFunction(second, (PyCodeblock*) third);
    first->setSelf(*func);

    return first;
}

Def::Def() {
    precedence = 16;
}
