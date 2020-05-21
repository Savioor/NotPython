//
// Created by alexey on 05/05/2020.
//

#ifndef BASICPYTHONINTERPRETER_MEMORYMANAGER_H
#define BASICPYTHONINTERPRETER_MEMORYMANAGER_H


#include <vector>
#include <map>
#include <string>
#include "PyClass.h"

class PyVariable;

class MemoryManager {

public:
    static MemoryManager& getManager();

    std::vector<PyClass*> memory;
    std::vector<std::vector<PyClass*>*> classesByExpDepth;
    std::vector<int> freeOpenCellsStack; // Vector can be used as a stack :)
    std::vector<std::map<std::string, PyVariable*>> namedVariableStack; // Stack depth dictated by code block depth

    void decreaseExpDepth();
    void increaseExpDepth();
    int allocateNewClass(PyClass*);
    void deallocateClass(int);
    int getCurrentDepth();

    void markAndSweep();

    PyClass* getVariable(const std::string& name);
    int allocateVariable(PyVariable* var);

protected:
    static MemoryManager* instance;
    int expressionDepth; // 0 = global expression aka the 'main' function.

private:
    MemoryManager& operator=(MemoryManager const&) = delete;
    MemoryManager(MemoryManager const&) = delete;
    MemoryManager();

};


#endif //BASICPYTHONINTERPRETER_MEMORYMANAGER_H
