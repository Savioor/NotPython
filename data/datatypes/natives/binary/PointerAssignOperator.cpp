//
// Created by alexey on 28/10/2019.
//

#include "PointerAssignOperator.h"
#include "../../../IOR.h"
#include "../../../Memory.h"
PyObject *PointerAssignOperator::execute(PyObject *left, PyObject *right) {

        if (left->getType() == "rvalue" || left->getType() == "bool"){
        IOR::getInstance().reportError("Can't perform assignment on rvalues or bools");
        return nullptr;
    }
    Memory& mem = Memory::getInstance();
    int leftPointer = mem.getPointerByObject(left);

    if (leftPointer == -1){
        IOR::getInstance().reportError("Variable not found in memory");
        return nullptr;
    }

    mem.getData().at(leftPointer) = right->yoink();
}

PointerAssignOperator::PointerAssignOperator() : BinaryNativeFunction("=") {

}
