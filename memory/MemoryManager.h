//
// Created by alexey on 05/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_MEMORYMANAGER_H
#define BASICPYTHONINTERPRETER_MEMORYMANAGER_H


#include <vector>
#include <map>
#include <string>
#include "Class.h"

class MemoryManager {

public:
    MemoryManager();

    std::vector<Class*> memory;
    std::vector<std::vector<Class*>*> classesByExpDepth;
    std::vector<int> freeOpenCellsStack; // Vector can be used as a stack :)
    std::vector<std::map<std::string, int>> namedVariableStack; // Stack depth dictated by code block depth

    void decreaseExpDepth();
    void increaseExpDepth();
    int allocateNewClass(Class*);

protected:
    int expressionDepth; // 0 = global expression aka the 'main' function.

};


#endif //BASICPYTHONINTERPRETER_MEMORYMANAGER_H
