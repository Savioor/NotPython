//
// Created by alexey on 26/10/2019.
//

#include <iostream>
#include "Print.h"
#include "../../../data/IOR.h"
#include "../../ExpressionParser.h"
#include "../../../data/datatypes/primitive/PyString.h"
#include "../../../data/datatypes/AnonymousObject.h"

stringIter_t &Print::parse(stringIter_t &ip, stringIter_t &end, IRequester& req) {

    PyObject* value = ExpressionParser::getInstance().parseExpression(ip, end);
    if (value == nullptr){
        IOR::getInstance().reportError("Error parsing expression");
        return end;
    }

    if (value->getType() == "rvalue"){
        value = ((AnonymousObject *) value)->getObject();
        if (value == nullptr){
            IOR::getInstance().reportError("Error parsing expression");
            return end;
        }
    }

    if (value->getType() != "string"){
        // TODO implement call to __str__
        IOR::getInstance().reportError("String expected! temp");
        return end;
    } else {
        IOR::getInstance().reportOut(((PyString*)value)->myValue);
        return end;
    }
}

Print::Print() : AbstractKeyword("print") {

}
