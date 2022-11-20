//
// Created by alexey on 03/06/2020.
//

#include "Append.h"
#include "../../../PyVariable.h"
#include "../../../../MemoryManager.h"

PyClass *Append::process(std::map<std::string, PyClass *> &map) {
    PyList* listInQuestion = (PyList*)&map["self"]->getRaw();
    listInQuestion->pushBack(&map["toInsert"]->getRaw());
    return listInQuestion;
}

Append::Append() : PyInternalFunction(nullptr) {
    PyList* params = new PyList(0);
    params->pushBack(new PyVariable("self", false));
    params->pushBack(new PyVariable("toInsert", false));
    pointerMap["p"] = new PyVariable(params);
    allowCollection = false;
}
