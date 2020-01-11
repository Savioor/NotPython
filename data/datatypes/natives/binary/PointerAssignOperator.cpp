//
// Created by alexey on 28/10/2019.
//

#include "PointerAssignOperator.h"
#include "../../../IOR.h"
#include "../../../memory-structure/Pool.h"
#include "../../../../debug.h"

pointerValuePair_t PointerAssignOperator::execute(pointerValuePair_t left, objectLoc_t right) {

    PyObject* leftO = get(left.second);
    PyObject* rightO = get(right);

    if (leftO->isConst()){
        IOR::getInstance().reportError("Can't perform assignment on constants");
        return {};
    }
    Memory& mem = Memory::getInstance();

#if ASSIGN_DEBUG == true
    IOR::getInstance().reportDebug("Assigning pointer");
#endif

    left.first->allocateHere() = rightO;
}

PointerAssignOperator::PointerAssignOperator() {

}
