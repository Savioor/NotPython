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

    if (!value->isPrimitive()){
        // TODO implement call to __str__
        IOR::getInstance().reportError("Primitive expected! temp");
        return end;
    } else {
        std::string&& toPrint = ((PyPrimitive*)value)->asStr();
        IOR::getInstance().reportOut(toPrint);
        return end;
    }
}

Print::Print() : AbstractKeyword("print") {

}
