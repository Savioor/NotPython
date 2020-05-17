//
// Created by USER on 5/13/2020.
//

#include "StringLiteral.h"
#include "../../../memory/builtins/PyString.h"

EncapsulatingOperator *StringLiteral::supplySelf() {
    return new StringLiteral(isDoubleQuote);
}

void StringLiteral::supplyInnards(std::string *innards) {
    value = innards;
}

bool StringLiteral::atEncapsulationEnd(char currChar) {
    bool ret = !isInsideString(true, isDoubleQuote, lastChar, currChar);
    lastChar = currChar;
    return ret;
}

StringLiteral::StringLiteral(bool isDQ) : lastChar('\0'), isDoubleQuote(isDQ) {

}

PyClass *StringLiteral::getAsClass() const {
    return new PyString(std::move(*value));
}
