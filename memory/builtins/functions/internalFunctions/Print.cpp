//
// Created by USER on 6/1/2020.
//

#include <iostream>
#include "Print.h"
#include "../../PyVariable.h"
#include "../../primitive/PyString.h"
#include "../../../MemoryManager.h"

PyClass *Print::process(std::map<std::string, PyClass *> &map) {
    const PyString* asStr = map["data"]->asString();
    if (asStr == nullptr) {
        std::cout << map["data"] << std::endl;
    } else {
        std::cout << asStr->getValue() << std::endl;
    }
    return MemoryManager::getManager().getNone();
}

Print::Print() : PyInternalFunction(new PyVariable("data", false)) {}
