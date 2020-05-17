//
// Created by alexey on 05/05/2020.
//

#include <iostream>
#include "MemoryManager.h"
#include "../debug.h"
#include "builtins/PyInteger.h"
#include "builtins/PyVariable.h"

MemoryManager* MemoryManager::instance = nullptr;

void MemoryManager::decreaseExpDepth() {
    expressionDepth--;
    std::vector<PyClass*>* temp = classesByExpDepth.at(classesByExpDepth.size() - 1);
    classesByExpDepth.pop_back();

    for (auto & i : *temp){
        i->references -= 1;
        i->expressionDepth = 0; // After the expression is parsed, variable enters global state
    }

    delete temp;

}

void MemoryManager::increaseExpDepth() {
    expressionDepth++;
    classesByExpDepth.push_back(new std::vector<PyClass*>());
}

MemoryManager::MemoryManager() : namedVariableStack{}, freeOpenCellsStack{}, memory{} {
    expressionDepth = 0;
    namedVariableStack.emplace_back();
    classesByExpDepth = std::vector<std::vector<PyClass*>*>();

}

int MemoryManager::allocateNewClass(PyClass* newClass) {

    if (newClass->expressionDepth >= 0) {
        throw std::runtime_error("Attempting to allocate class that was already allocated");
    }

#if MEM_ALLOC_DEBUG
    std::cout << "Allocating new class. Current classes allocated = " << (1 + memory.size() - freeOpenCellsStack.size()) << std::endl;
#endif

    classesByExpDepth.at(classesByExpDepth.size() - 1)->push_back(newClass);
    newClass->expressionDepth = getCurrentDepth();

    if (freeOpenCellsStack.empty()) {
        memory.push_back(newClass);
        return (int)(memory.size() - 1);
    } else {
        int emptyLocation = freeOpenCellsStack.at(freeOpenCellsStack.size() - 1);
        freeOpenCellsStack.pop_back();
        memory.assign(emptyLocation, newClass);
        return emptyLocation;
    }

}

void MemoryManager::deallocateClass(int index) {
    PyClass* subject = memory.at(index);
    if (subject == nullptr) {
#if MEM_ALLOC_DEBUG
        std::cout << "attempted dealloc class at " << index << " that was nullptr";
#endif
        return;
    }
#if MEM_ALLOC_DEBUG
    std::cout << "deallocing class at " << index << " that has " << subject->references << " references.";
#endif
    if (subject->expressionDepth != 0) {
        throw std::runtime_error("Attempting to dealloc class that is still used in an expression");
    }

    delete(subject);
    memory.assign(index, nullptr);
    freeOpenCellsStack.push_back(index);

}

MemoryManager &MemoryManager::getManager() {
    if (instance == nullptr) {
        instance = new MemoryManager();
    }
    return *instance;
}

int MemoryManager::getCurrentDepth() {
    return classesByExpDepth.size();
}

PyClass *MemoryManager::getVariable(const std::string &name) {
    // TODO code blocks don't exist yet so I'm writing shit code for now
    if (namedVariableStack.at(0).count(name) == 0) {
        return new PyVariable(name);
    } else {
        return namedVariableStack.at(0).at(name);
    }
    return nullptr;
}

void MemoryManager::allocateVariable(PyVariable *var) {
    // TODO same as getVariable function
    namedVariableStack.at(0).insert({var->getName(), var});
}
