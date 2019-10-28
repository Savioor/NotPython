//
// Created by alexey on 28/10/2019.
//

#include "PointerAssignOperator.h"
#include "../../../IOR.h"
#include "../../../Memory.h"
#include "../../AnonymousObject.h"

PyObject *PointerAssignOperator::execute(PyObject *left, PyObject *right) {
    if (left->getType() == "rvalue"){
        IOR::getInstance().getErr().emplace_back("Can't perform assignment on rvalues");
        return nullptr;
    }
    Memory& mem = Memory::getInstance();
    int leftPointer = mem.getPointerByObject(left);

    if (leftPointer == -1){
        IOR::getInstance().getErr().emplace_back("Variable not found in memory");
        return nullptr;
    }

    if (right->getType() != "rvalue")
        mem.getData().at(leftPointer) = right;
    else
        mem.getData().at(leftPointer) = ((AnonymousObject*)right)->getObj();
}

PointerAssignOperator::PointerAssignOperator() : BinaryNativeFunction("=") {

}
