//
// Created by alexey on 31/05/2020.
//

#include "ClassCreation.h"
#include "../../../memory/MemoryManager.h"
#include "../../../memory/builtins/PyCodeblock.h"
#include "../../../memory/builtins/PyVariable.h"
#include "../../../memory/builtins/classes/PyClassStructure.h"

PyClass *ClassCreation::reduce(PyClass *first, PyClass *second, PyClass *third) {
    if (first->type != pyVAR ||
        (second->type != pyARRAY && second->type != pyVAR && second != MemoryManager::getManager().getNone()) ||
        third->type != pyCODE_BLOCK) {
        throw std::runtime_error("Attempting to define class with illegal operators");
    }

    PyClassStructure* returnStructure = new PyClassStructure();
    PyCodeblock* asCB = (PyCodeblock*) third;

    MemoryManager::getManager().increaseStackDepth();

    asCB->runAsClassStructure();
    std::map<std::string, PyVariable*>& createdVars =
            MemoryManager::getManager().namedVariableStack.at(MemoryManager::getManager().getCurrentDepth());

    for (auto& x : createdVars) {
        returnStructure->pointerMap.insert({x.first, x.second});
    }

    MemoryManager::getManager().decreaseStackDepth();

    // TODO inheritence

    first->setSelf(*returnStructure);
    return returnStructure;
}

ClassCreation::ClassCreation() {
    precedence = 16;
}
