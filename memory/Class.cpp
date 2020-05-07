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

static_ver_bin_impl(add, leftAdd);
static_ver_bin_impl(sub, leftSub);
static_ver_bin_impl(mult, leftMult);
static_ver_bin_impl(div, leftDiv);
static_ver_bin_impl(mod, leftModulu);
static_ver_bin_impl(pow, leftPower);



