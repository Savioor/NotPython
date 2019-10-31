//
// Created by alexey on 24/10/2019.
//

#include <iostream>
#include "IOR.h"


void IOR::reportError(std::string &in) {
    reportError(in.c_str());
}

void IOR::reportError(const char *in) {
    std::cerr << in << std::endl;
}

void IOR::reportOut(std::string &in) {
    reportOut(in.c_str());
}

void IOR::reportOut(const char *in) {
    std::cout << in << std::endl;

}
