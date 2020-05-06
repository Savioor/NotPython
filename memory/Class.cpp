//
// Created by alexey on 17/04/2020.
//

#include "Class.h"
#include "MemoryManager.h"

Class::Class() {

    references = 1;
    expressionDepth = -1;
    memoryAllocationLocation = MemoryManager::getManager().allocateNewClass(this);
    type = pyOTHER;

}
