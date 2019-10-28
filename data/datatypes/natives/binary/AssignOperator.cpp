//
// Created by alexey on 28/10/2019.
//

#include "AssignOperator.h"
#include "../../../IOR.h"
#include "../../../Memory.h"

PyObject *AssignOperator::execute(PyObject *left, PyObject *right) {
    if (left->getType() == "rvalue"){ // TODO actually add rvalues
        IOR::getInstance().getErr().emplace_back("Can't perform assignment on rvalues");
        return nullptr;
    }

}

AssignOperator::AssignOperator() : BinaryNativeFunction("=") {

}
