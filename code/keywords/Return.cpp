//
// Created by alexey on 01/11/2019.
//

#include "Return.h"
#include "../ExpressionParser.h"
#include "../../data/IOR.h"

stringIter_t &Return::parse(stringIter_t &ip, stringIter_t &end, IRequester &req) {
    int returnValue = ExpressionParser::getInstance().parseExpression(ip, end);
    if (returnValue == -1){
        IOR::getInstance().reportError("Expected some value to return, none found!");
    }
    static Memory& mem = Memory::getInstance();
    static std::string retName{RETURN_VAR_NAME};
    mem.allocPointer(retName, returnValue);
    return end;
}

Return::Return() : AbstractKeyword("return") {

}
