//
// Created by alexey on 17/04/2020.
//

#include "PyClass.h"
#include "MemoryManager.h"
#include "builtins/PyVariable.h"

PyClass::PyClass() {

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

static_ver_bin_impl_deep(pyAnd, leftAnd, PyBool);
static_ver_bin_impl_deep(pyOr, leftOr, PyBool);
static_ver_bin_impl_deep(eql, leftEql, PyBool);
static_ver_bin_impl_deep(bigger, leftBigger, PyBool);
static_ver_bin_impl_deep(smaller, leftSmaller, PyBool)

PyClass *PyClass::setSelf(PyClass &other) { // Only used by PyVariable really, so I'm supplying a default impl
    return nullptr;
}

PyClass *PyClass::getSelf() {
    if (type == pyOTHER) return this;
    if (type == pyVAR) return ((PyVariable*)this)->getChild();
    return nullptr;
}

