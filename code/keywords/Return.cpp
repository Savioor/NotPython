//
// Created by alexey on 01/11/2019.
//

#include "Return.h"
#include "../ExpressionParser.h"
#include "../../data/IOR.h"

stringIter_t &Return::parse(stringIter_t &ip, stringIter_t &end, IRequester &req) {
    PyObject* returnValue = ExpressionParser::getInstance().parseExpression(ip, end);
    if (returnValue == nullptr){
        IOR::getInstance().reportError("Expected some value to return, none found!");
    }
    static Memory& mem = Memory::getInstance();
    static std::string retName{RETURN_VAR_NAME};
    mem.allocPointer(retName, mem.alloc(returnValue));
    return end;
}

Return::Return() : AbstractKeyword("return") {

}
