//
// Created by alexey on 25/10/2019.
//

#include "Memory.h"
#include "IOR.h"
#include "datatypes/primitive/PyBoolean.h"

#if MEM_DEBUG
    int Memory::currentlyAlloced = 0;
#endif


// TODO add defragmentation
void Memory::collectGarbage() {
    if (!garbageCollectorRunning)
        return;

    int latestInd = -1;
    std::vector<PyObject*> marked;
    bool* markedStatus = new bool[data.size()];
    for (int i = 0; i < data.size(); i++)
        markedStatus[i] = false;
    bool markedSomeone;

    // Mark everyone
    while (true){ // TODO tidy up a bit
        markedSomeone = false;

        if (latestInd == -1){
            latestInd = 0;
            for (auto& pair : pointerTable){
                PyObject* pointingTo = data.at(pair.second);
                if (markedStatus[pair.second]) continue;
                markedSomeone = true;
                markedStatus[pair.second] = true;
                marked.push_back(pointingTo);
            }
        } else {
            int i = latestInd;
            latestInd = marked.size();
            for (; i < latestInd; i++){
                for (auto& pair : marked.at(i)->getData()){
                    PyObject* pointingTo = data.at(pair.second);
                    if (markedStatus[pair.second]) continue;
                    markedSomeone = true;
                    markedStatus[pair.second] = true;
                    marked.push_back(pointingTo);
                }
            }
        }


        if (!markedSomeone) break;
    }

    for (int i = 0; i < data.size(); i++){
        if (!markedStatus[i] && data.at(i) != nullptr && !data.at(i)->isConst()) {
#if MEM_DEBUG
            currentlyAlloced--;
            IOR::getInstance().reportDebug("GC deleting object of type " + data.at(i)->getType()
            + ". Currently alloced = " + std::to_string(currentlyAlloced));
#endif
            delete(data.at(i));
            data.at(i) = nullptr;
        }
    }

}

std::vector<PyObject*> &Memory::getData() {
    return data;
}

std::map<std::pair<std::string, int>, int> &Memory::getPointers() {
    return pointerTable;
}

int Memory::alloc(PyObject &obj) {
    int existingPtr = getPointerByObject(&obj);
    if (existingPtr != -1)
        return existingPtr;
    allocCount++;
    if (allocCount % GC_FREQ == 0)
        collectGarbage();
    data.push_back(&obj);

#if MEM_DEBUG
    currentlyAlloced++;
    IOR::getInstance().reportDebug("Allocated new object of type " + obj.getType() + ". Currently alloced = "
    + std::to_string(currentlyAlloced));
#endif

    return (int)data.size() - 1;
}

void Memory::allocPointer(std::string & varName, int pointer) {
    pointerTable.insert({{varName, depth}, pointer});
}

void Memory::allocPointer(std::string && varName, int pointer) {
    pointerTable.insert({{varName, depth}, pointer});
}


Memory::Memory() : depth(0), allocCount(0), garbageCollectorRunning(true) {

    // Alloc some basic vars
    this->allocPointer(*new std::string("true"), this->allocConst(new PyBoolean(true)));
    this->allocPointer(*new std::string("false"), this->allocConst(new PyBoolean(false)));

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
        if (var != nullptr) delete(var);
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

void Memory::enableGC() {
    garbageCollectorRunning = true;
#if MEM_DEBUG == true
    if (!garbageCollectorRunning) IOR::getInstance().reportDebug("GC on");
#endif

}

void Memory::disableGC() {
    garbageCollectorRunning = false;
#if MEM_DEBUG
    if (garbageCollectorRunning) IOR::getInstance().reportDebug("GC off");
#endif
}

void Memory::manuallyRemove(PyObject *obj) {
    for (int i = 0; i < data.size(); i++){
        if (data.at(i) == obj){
            data.at(i) = nullptr;
#if MEM_DEBUG
            currentlyAlloced--;
            IOR::getInstance().reportDebug("Manually removed object from memory. Currently alloced = " + std::to_string(currentlyAlloced));
#endif
            break;
        }
    }
}
