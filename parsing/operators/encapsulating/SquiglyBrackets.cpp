//
// Created by alexey on 26/05/2020.
//

#include "SquiglyBrackets.h"
#include "../../../memory/builtins/PyCodeblock.h"

// TODO after I push at home update with proper Brackets code

void SquiglyBrackets::supplyInnards(std::string *innards) {
    asCodeBlock = new PyCodeblock(std::move(*innards));
}

bool SquiglyBrackets::atEncapsulationEnd(char currChar) {

    if (isInsideString(inString, isDoubleQuoteString, lastChar, currChar)) {
        if (!inString){
            inString = true;
            isDoubleQuoteString = currChar == '\"';
        }
        goto retFalse;
    } else {
        inString = false;
    }

    if (currChar == '}') {
        if (bracketDepthCount != 0) {
            bracketDepthCount--;
            goto retFalse;
        } else {
            goto retTrue;
        }
    }
    if (currChar == '{') {
        bracketDepthCount++;
    }

    retFalse:
    lastChar = currChar;
    return false;
    retTrue:
    lastChar = currChar;
    return true;

}

PyClass *SquiglyBrackets::getAsClass() const {
    return asCodeBlock;
}

SquiglyBrackets::SquiglyBrackets() : bracketDepthCount(0), lastChar('\0'),
                       inString(false), isDoubleQuoteString(false) {}

EncapsulatingOperator *SquiglyBrackets::supplySelf() {
    return new SquiglyBrackets();
}

