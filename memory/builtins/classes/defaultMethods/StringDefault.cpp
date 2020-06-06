//
// Created by USER on 6/6/2020.
//

#include <sstream>
#include "../../primitive/PyString.h"
#include "StringDefault.h"

PyClass *StringDefault::process(std::map<std::string, PyClass *> &map) {
    const void* target = map["self"];
    std::stringstream ss;
    ss << target;
    return new PyString(ss.str());
}

StringDefault::StringDefault(PyClass * c) : PyInternalFunction(c) {

}
