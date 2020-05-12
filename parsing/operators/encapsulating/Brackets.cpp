//
// Created by USER on 5/8/2020.
//

#include <sstream>
#include "Brackets.h"
#include "../../ExpressionParser.h"

void Brackets::supplyInnards(std::string *innards) {
    expr = innards;
}

bool Brackets::atEncapsulationEnd(char currChar) {

    if (isInsideString(inString, isDoubleQuoteString, lastChar, currChar)) {
        if (!inString){
            inString = true;
            isDoubleQuoteString = currChar == '\"';
        }
        goto retFalse;
    } else {
        inString = false;
    }

    if (currChar == ')') {
        if (bracketDepthCount != 0) {
            bracketDepthCount--;
            goto retFalse;
        } else {
            goto retTrue;
        }
    }
    if (currChar == '(') {
        bracketDepthCount++;
    }

    retFalse:
    lastChar = currChar;
    return false;
    retTrue:
    lastChar = currChar;
    return true;

}

Class *Brackets::getAsClass() const {
    std::istringstream ss{*expr + ";"}; // TODO this is slow and temporary (but it should work)
    return ExpressionParser().parse(ss);
}

Brackets::Brackets() : bracketDepthCount(0), lastChar('\0'),
                       inString(false), isDoubleQuoteString(false) {}

EncapsulatingOperator *Brackets::supplySelf() {
    return new Brackets();
}
