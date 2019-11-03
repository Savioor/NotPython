//
// Created by alexey on 26/10/2019.
//

#include "Print.h"
#include "../../../data/IOR.h"
#include "../../ExpressionParser.h"
#include "../../../data/datatypes/primitive/PyString.h"

stringIter_t &Print::parse(stringIter_t &ip, stringIter_t &end, IRequester& req) {

    int ptr = ExpressionParser::getInstance().parseExpression(ip, end);
    if (ptr == -1){
        IOR::getInstance().reportError("Error parsing expression");
        return end;
    }

    PyObject* value = Memory::getInstance().getData().at(ptr)->unmask();

    if (value == nullptr){
        IOR::getInstance().reportError("Error parsing expression");
        return end;
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
