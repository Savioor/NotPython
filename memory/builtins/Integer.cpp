//
// Created by USER on 5/5/2020.
//

#include <ostream>
#include "Integer.h"
#include <cmath>
#include <iostream>
#include "../../debug.h"


Class *Integer::leftAdd(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(value + dynamic_cast<Integer const&>(rightElem).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::leftMult(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(value * dynamic_cast<Integer const&>(rightElem).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::leftDiv(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(value / dynamic_cast<Integer const&>(rightElem).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::leftSub(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(value - dynamic_cast<Integer const&>(rightElem).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::leftModulu(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(value % dynamic_cast<Integer const&>(rightElem).value);
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::leftPower(Class const &rightElem) {
    switch (rightElem.type){
        case pyINTEGER:
            return new Integer(std::round(std::pow(value, dynamic_cast<Integer const&>(rightElem).value)));
        case pyDOUBLE:

            break;
        case pySTRING:

            break;
    }
    return nullptr;
}

Class *Integer::negate() {
    return nullptr;
}

Class *Integer::call(Class const &params) {
    return nullptr;
}

Class *Integer::asString() {
    return nullptr;
}

Class *Integer::getElem(Class const &indexer) {
    return nullptr;
}

Class *Integer::setElem(Class const &indexer, Class const &newElem) {
    return nullptr;
}

int Integer::getValue() const{
    return value;
}


Integer::Integer(int64_t val) : Class() {
    type = pyINTEGER;
    value = val;
#if MEM_ALLOC_DEBUG
    std::cout << "This class is an integer with value " << val << std::endl;
#endif
}
