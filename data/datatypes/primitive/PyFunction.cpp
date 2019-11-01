//
// Created by alexey on 29/10/2019.
//

#include "PyFunction.h"
#include "../../IOR.h"
#include "../../Memory.h"
#include "../../../code/parsers/FunctionParser.h"
#include "../../../code/reqeusters/VectorRequester.h"


PyFunction::PyFunction(std::vector<std::string>& code, std::vector<std::string>& vars) : PyObject("func"), code(code), inputVariables(vars) {

}

const std::vector<std::string> &PyFunction::getInputNames() {
    return inputVariables;
}

PyObject *PyFunction::execute(std::vector<PyObject *> &input) {
    // Check if number of inputs match
    if (input.size() != inputVariables.size()){
        IOR::getInstance().reportError("Function variable amount doesn't match");
        return nullptr;
    }
    // Alloc all memory
    int alloc;
    Memory& mem = Memory::getInstance();
    mem.depth += 1;
    for (int i = 0; i < input.size(); i++){
        alloc = mem.alloc(input.at(i)->unmask());
        mem.allocPointer(inputVariables.at(i), alloc);
    }
    // Run the code for the function
    FunctionParser tempParser{};
    VectorRequester requester{code};
    while(tempParser.parseLine(requester));
    // Get the return value of this function
    std::string retName{"return"};
    PyObject* retVal = mem.getVariable(retName);
    // Exit the function, kill all pointers
    for (int i = 0; i < input.size(); i++){
        mem.killPointer(inputVariables.at(i), mem.depth);
    }
    mem.killPointer(retName, mem.depth);
    mem.depth -= 1;
    return retVal;
}