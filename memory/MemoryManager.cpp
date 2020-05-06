//
// Created by alexey on 05/05/2020.
//

#include <iostream>
#include "MemoryManager.h"
#include "../debug.h"

MemoryManager* MemoryManager::instance = nullptr;

void MemoryManager::decreaseExpDepth() {
    expressionDepth--;
    std::vector<Class*>* temp = classesByExpDepth.at(classesByExpDepth.size() - 1);
    classesByExpDepth.pop_back();

    for (auto & i : *temp){
        i->references -= 1;
        i->expressionDepth = 0; // After the expression is parsed, variable enters global state
    }

    delete temp;

}

void MemoryManager::increaseExpDepth() {
    expressionDepth++;
    classesByExpDepth.push_back(new std::vector<Class*>());
}

MemoryManager::MemoryManager() {
    expressionDepth = 0;
    memory = std::vector<Class*>();
    namedVariableStack = std::vector<std::map<std::string, int>>();
    freeOpenCellsStack = std::vector<int>();
    classesByExpDepth = std::vector<std::vector<Class*>*>();

}

int MemoryManager::allocateNewClass(Class* newClass) {

    if (newClass->expressionDepth >= 0) {
        throw std::runtime_error("Attempting to allocate class that was already allocated");
    }

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
    Class* subject = memory.at(index);
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
