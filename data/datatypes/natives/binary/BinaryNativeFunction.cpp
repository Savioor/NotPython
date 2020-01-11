//
// Created by alexey on 28/10/2019.
//

#include "BinaryNativeFunction.h"

const std::string &BinaryNativeFunction::getName() const {
    return name;
}

BinaryNativeFunction::BinaryNativeFunction(char * in) : PyObject(BinaryOperator), name(in) {

}

BinaryNativeFunction::BinaryNativeFunction(std::string && in) : PyObject(BinaryOperator), name(in) {

}