//
// Created by alexey on 26/10/2019.
//

#include <iostream>
#include "Print.h"
#include "../../../data/IOR.h"
#include "../../ExpressionParser.h"
#include "../../../data/datatypes/primitive/PyString.h"

stringIter_t &Print::parse(stringIter_t &ip, stringIter_t &end) {
    if (*ip.base() != ' '){
        IOR::getInstance().getErr().emplace_back("Expected space but none was found");
        return end;
    }
    ip++;
    PyObject* value = ExpressionParser::getInstance().parseExpression(ip, end);
    if (value == nullptr){
        IOR::getInstance().getErr().emplace_back("Error parsing expression");
        return end;
    }

    if (value->getType() != "string"){
        // TODO implement call to __str__
        IOR::getInstance().getErr().emplace_back("String expected! temp");
        return end;
    } else {
        IOR::getInstance().getOut().emplace_back(((PyString*)value)->myValue);
        return end;
    }
}

Print::Print() : AbstractKeyword("print") {

}
