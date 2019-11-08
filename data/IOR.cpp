//
// Created by alexey on 24/10/2019.
//

#include <iostream>
#include "IOR.h"


void IOR::reportError(const std::string &in) {
    reportError(in.c_str());
}

void IOR::reportError(const char *in) {
    std::cerr << in << std::endl;
}

void IOR::reportOut(const std::string &in) {
    reportOut(in.c_str());
}

void IOR::reportOut(const char *in) {
    std::cout << in << std::endl;

}

void IOR::reportDebug(const std::string &in) {
    reportDebug(in.c_str());
}

void IOR::reportDebug(const char *in) {
    std::cout << "\033[1;35m" << in << "\033[0m" << std::endl;
}

void IOR::reportDebug(const std::string && in) {
    reportDebug(in.c_str());
}

void IOR::reportError(const std::string && ipn) {
    reportError(ipn.c_str());
}
