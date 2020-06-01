//
// Created by alexey on 05/05/2020.
//

#include <iostream>
#include "MemoryManager.h"
#include "../debug.h"
#include "builtins/primitive/PyInteger.h"
#include "builtins/primitive/PyBool.h"
#include "builtins/PyVariable.h"
#include "builtins/PyList.h"
#include "builtins/functions/internalFunctions/Print.h"

MemoryManager *MemoryManager::instance = nullptr;

void MemoryManager::decreaseExpDepth() {
    expressionDepth--;

#if EXPR_DEPTH
    std::cout << "Expr depth now " << expressionDepth << std::endl;
#endif

    std::vector<PyClass *> *temp = classesByExpDepth.at(classesByExpDepth.size() - 1);
    classesByExpDepth.pop_back();

    for (PyClass *i : *temp) {
        i->references -= 1;
        i->expressionDepth = 0; // After the expression is parsed, variable enters global state
    }

    delete temp;
}

void MemoryManager::increaseExpDepth() {
    expressionDepth++;
#if EXPR_DEPTH
    std::cout << "Expr depth now " << expressionDepth << std::endl;
#endif
    classesByExpDepth.push_back(new std::vector<PyClass *>());
}

MemoryManager::MemoryManager() : namedVariableStack{}, freeOpenCellsStack{}, memory{} {
    expressionDepth = 0;
    namedVariableStack.emplace_back();
    classesByExpDepth = std::vector<std::vector<PyClass *> *>();

    NONE = nullptr;

}

int MemoryManager::allocateNewClass(PyClass *newClass) {

    if (newClass->expressionDepth >= 0) {
        throw std::runtime_error("Attempting to allocate class that was already allocated");
    }

#if MEM_ALLOC_DEBUG
    std::cout << "Allocating new class. Current classes allocated = " << (1 + memory.size() - freeOpenCellsStack.size())
              << std::endl;
#endif

    classesByExpDepth.at(classesByExpDepth.size() - 1)->push_back(newClass);
    newClass->expressionDepth = getCurrentDepth();

    if (freeOpenCellsStack.empty()) {
        memory.push_back(newClass);
        return (int) (memory.size() - 1);
    } else {
        int emptyLocation = freeOpenCellsStack.at(freeOpenCellsStack.size() - 1);
        freeOpenCellsStack.pop_back();
        memory[emptyLocation] = newClass;
        return emptyLocation;
    }

}

void MemoryManager::deallocateClass(int index) {
    PyClass *subject = memory.at(index);
    if (subject == nullptr) {
#if MEM_ALLOC_DEBUG
        std::cout << "attempted dealloc class at " << index << " that was nullptr";
#endif
        return;
    }
#if MEM_ALLOC_DEBUG
    std::cout << "deallocing class at " << index << " that has " << subject->references << " references." << std::endl;
#endif
    if (subject->expressionDepth != 0) {
        throw std::runtime_error("Attempting to dealloc class that is still used in an expression");
    }

    memory[index] = nullptr;
    delete (subject);
    freeOpenCellsStack.push_back(index);

#if MEM_ALLOC_DEBUG
    std::cout << "Current classes allocated = " << (1 + memory.size() - freeOpenCellsStack.size()) << std::endl;
#endif

}

MemoryManager &MemoryManager::getManager() {
    if (instance == nullptr) {
        instance = new MemoryManager();
        instance->addInternalFunctions();
    }
    return *instance;
}

int MemoryManager::getCurrentDepth() {
    return classesByExpDepth.size();
}

PyClass *MemoryManager::getVariable(const std::string &name) {
    int lastElem = namedVariableStack.size() - 1;
    for (int i = lastElem; i >= 0; i--) {
        if (namedVariableStack.at(i).count(name) != 0) {
            return namedVariableStack.at(i).at(name);
        }
    }
    return new PyVariable(name);
}

int MemoryManager::allocateVariable(PyVariable *var) {
    namedVariableStack.at(getCurrentStackDepth()).insert({var->getName(), var});
    var->myDepth = getCurrentStackDepth();
    return getCurrentStackDepth();
}

void MemoryManager::markAndSweep() { // TODO run it properly and automatically

#if GC_DEBUG
    std::cout << "running GC!" << std::endl;
#endif

    for (auto *cls : memory) {
        if (cls == nullptr) continue;
        cls->marked = false;
    }

    for (auto mp : namedVariableStack) {
        for (auto it = mp.begin(); it != mp.end(); it++) {
            PyClass *child = it->second;
            if (child != nullptr && !child->marked) {
                child->marked = true; // TODO test with pointerMaps
                markPointerMapOf(child);
            }
        }
    }

    PyClass *cls;
    for (int i = 0; i < memory.size(); i++) {
        cls = memory.at(i);
        if (immune(cls)) continue;
        deallocateClass(i);
    }

#if GC_DEBUG
    std::cout << "running GC finished!" << std::endl;
#endif

}

void MemoryManager::markPointerMapOf(PyClass *cls) {

    // TODO consider switching to iterative stack impl

    auto &pointerMap = cls->pointerMap;

    if (cls->type == pyARRAY) { // This is here because it allows list operation to be more efficient

        auto* asLs = (PyList*) cls;

        for (auto& elem : asLs->getElements()){
            if (elem->marked) continue;
            elem->marked = true;
            markPointerMapOf(elem);
        }

    } else {
        for (auto it = pointerMap.begin(); it != pointerMap.end(); it++) {
            if (it->second == nullptr || it->second->marked) continue;
            it->second->marked = true;
            markPointerMapOf(it->second);
        }

    }


}

PyClass *MemoryManager::getNone() {
    if (NONE == nullptr) {
        increaseExpDepth();
        NONE = new PyInteger(0);
        decreaseExpDepth();
    }
    return NONE;
}

void MemoryManager::increaseStackDepth() {
    namedVariableStack.emplace_back();
}

void MemoryManager::decreaseStackDepth() {
    namedVariableStack.pop_back();
}

bool MemoryManager::immune(PyClass *cls) {
    return cls == nullptr || cls->marked || cls->expressionDepth != 0 || cls == NONE || cls == TRUE || cls == FALSE;
}

PyClass *MemoryManager::getTrue() {
    if (TRUE == nullptr) {
        increaseExpDepth();
        TRUE = new PyBool(true);
        decreaseExpDepth();
    }
    return TRUE;
}

PyClass *MemoryManager::getFalse() {
    if (FALSE == nullptr) {
        increaseExpDepth();
        FALSE = new PyBool(false);
        decreaseExpDepth();
    }
    return FALSE;
}

int MemoryManager::getCurrentStackDepth() {
    return namedVariableStack.size() - 1;
}

PyVariable *MemoryManager::allocateAndAssign(std::string& str, PyClass *value) {
    PyVariable* newVar = new PyVariable(str);
    newVar->setSelf(*value);
    return newVar;
}
PyVariable *MemoryManager::allocateAndAssign(std::string&& str, PyClass *value) {
    PyVariable* newVar = new PyVariable(str);
    newVar->setSelf(*value);
    return newVar;
}

void MemoryManager::addInternalFunctions() {
    increaseExpDepth();
    allocateAndAssign("print", new Print());
    decreaseExpDepth();
}
