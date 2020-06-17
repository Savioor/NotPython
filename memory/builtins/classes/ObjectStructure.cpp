//
// Created by USER on 6/6/2020.
//

#include "ObjectStructure.h"
#include "defaultMethods/StringDefault.h"
#include "../PyVariable.h"

ObjectStructure::ObjectStructure() : PyClassStructure(0) {

    pointerMap.insert({"__str__",
                       new PyVariable(new StringDefault(new PyVariable("self", false)))});

}
