//
// Created by alexey on 24/10/2019.
//

#include "IOR.h"

IOR::IOR() : in(), out(), err() {
}

const strList &IOR::getIn() const {
    return in;
}

const strList &IOR::getOut() const {
    return out;
}

const strList &IOR::getErr() const {
    return err;
}

strList &IOR::getIn() {
    return in;
}

strList &IOR::getOut() {
    return out;
}

strList &IOR::getErr() {
    return err;
}
