//
// Created by alexey on 28/10/2019.
//

#include "PointerAssignOperator.h"
#include "../../../IOR.h"
#include "../../../Memory.h"
#include "../../../../debug.h"

PyObject *PointerAssignOperator::execute(PyObject *left, PyObject *right) {

        if (left->getType() == "rvalue" || left->isConst()){
        IOR::getInstance().reportError("Can't perform assignment on rvalues or constants");
        return nullptr;
    }
    Memory& mem = Memory::getInstance();
    int leftPointer = mem.getPointerByObject(left);

    if (leftPointer == -1){
        IOR::getInstance().reportError("Variable not found in memory");
        return nullptr;
    }

#if ASSIGN_DEBUG == true
    IOR::getInstance().reportDebug("Assigning pointer " + std::to_string(leftPointer));
#endif

    mem.getData().at(leftPointer) = right->yoink();
}

PointerAssignOperator::PointerAssignOperator() : BinaryNativeFunction("=") {

}
