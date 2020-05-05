//
// Created by alexey on 05/05/2020.
//

#include "MemoryManager.h"

void MemoryManager::decreaseExpDepth() {
    expressionDepth--;
    std::vector<Class*>* temp = classesByExpDepth.at(classesByExpDepth.size() - 1);
    classesByExpDepth.pop_back();

    for (auto & i : *temp){
        i->references -= 1;
        i->expressionDepth = 0; // After the expression is parsed, variable enter global state
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
