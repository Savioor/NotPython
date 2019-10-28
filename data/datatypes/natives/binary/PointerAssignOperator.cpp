//
// Created by alexey on 28/10/2019.
//

#include "PointerAssignOperator.h"
#include "../../../IOR.h"
#include "../../../Memory.h"

PyObject *PointerAssignOperator::execute(PyObject *left, PyObject *right) {
    if (left->getType() == "rvalue"){
        IOR::getInstance().getErr().emplace_back("Can't perform assignment on rvalues");
        return nullptr;
    }
    Memory& mem = Memory::getInstance();
    int leftPointer = mem.getPointerByObject(left);
    delete(left);
    mem.getData().at(leftPointer) = right;
}

PointerAssignOperator::PointerAssignOperator() : BinaryNativeFunction("=") {

}
