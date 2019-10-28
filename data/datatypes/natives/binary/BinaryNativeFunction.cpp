//
// Created by alexey on 28/10/2019.
//

#include "BinaryNativeFunction.h"

const std::string &BinaryNativeFunction::getName() const {
    return getType();
}

BinaryNativeFunction::BinaryNativeFunction(char * in) : PyObject("unary_native"), name(in) {

}

BinaryNativeFunction::BinaryNativeFunction(std::string && in) : PyObject("unary_native"), name(in) {

}