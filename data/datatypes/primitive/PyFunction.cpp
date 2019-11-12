//
// Created by alexey on 29/10/2019.
//

#include "PyFunction.h"
#include "../../IOR.h"
#include "../../Memory.h"
#include "../../../code/parsers/FunctionParser.h"
#include "../../../code/reqeusters/VectorRequester.h"
#include "../../../code/reqeusters/FunctionRequester.h"

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
        alloc = mem.getPointerByObject(input.at(i));
        if (alloc == -1) alloc = mem.alloc(input.at(i)->unmask());
        mem.allocPointer(inputVariables.at(i), alloc);
    }
    // Run the code for the function
    FunctionParser tempParser{};
    VectorRequester requester{code};
    FunctionRequester fReq{requester};
    while(tempParser.parseLine(fReq));
    // Get the return value of this function
    std::string retName{RETURN_VAR_NAME};
    PyObject* retVal = mem.getVariable(retName);
    mem.manuallyRemove(retVal);
    // Exit the function, kill all pointers
    for (int i = 0; i < input.size(); i++){
        mem.killPointer(inputVariables.at(i), mem.depth);
    }
    mem.killPointer(retName, mem.depth);
    mem.depth -= 1;

#if FUNCTION_RETURN_DEBUG
    IOR::getInstance().reportDebug("Returned value of type " + retVal->getType());
#endif

    return retVal;
}
