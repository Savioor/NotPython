//
// Created by alexey on 25/10/2019.
//

#include "Memory.h"

void Memory::collectGarbage() {
    throw "TODO";
}

std::vector<PyObject*> &Memory::getData() {
    return data;
}

std::map<std::pair<std::string, int>, int> &Memory::getPointers() {
    return pointerTable;
}

int Memory::alloc(PyObject &obj) {
    data.push_back(&obj);
    return (int)data.size() - 1;
}

void Memory::allocPointer(std::string & varName, int pointer) {
    pointerTable.insert({{varName, depth}, pointer});
}

Memory::Memory() : depth(0) {

}

std::vector<std::pair<PyObject *, int>> Memory::getAllVarMatches(std::string & var) {
    std::vector<std::pair<PyObject *, int>> ret;
    for (auto& pair : pointerTable){
        if (pair.first.first == var){
            ret.emplace_back(data.at(pair.second), pair.first.second);
        }
    }
    return std::move(ret);
}

PyObject *Memory::getVariable(std::string & var) {
    std::vector<std::pair<PyObject*, int>> options = getAllVarMatches(var);
    if (options.empty()){
        return nullptr; // No variable with that name exists
    }
    int largestIndex = 0;
    for (int i = 0; i < options.size(); i++){
        if (options.at(i).second > options.at(largestIndex).second){
            largestIndex = i;
        }
    }
    return options.at(largestIndex).first;
}

int Memory::getPointerByObject(PyObject *inp) {
    for (int i = 0; i < data.size(); i++){
        if (data.at(i) == inp){
            return i;
        }
    }
    return -1;
}

Memory::~Memory() {
    for (auto var : data){
        delete(var);
    }
}

void Memory::killPointer(const std::string &pointerName, int pointerDepth) {
    pointerTable.erase({pointerName, pointerDepth});
}

void Memory::reduceDepth(const std::string &varName, int currDepth) {
    for (auto& pair : pointerTable){
        if (pair.first.first == varName && pair.first.second == currDepth){
            pointerTable.insert({{pair.first.first, currDepth - 1}, pair.second});
            pointerTable.erase({varName, currDepth });
            return;
        }
    }
}
