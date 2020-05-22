//
// Created by USER on 5/8/2020.
//

#include <sstream>
#include "Brackets.h"

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

    if (currChar == closingChar) {
        if (bracketDepthCount != 0) {
            bracketDepthCount--;
            goto retFalse;
        } else {
            goto retTrue;
        }
    }
    if (currChar == openingChar) {
        bracketDepthCount++;
    }

    retFalse:
    lastChar = currChar;
    return false;
    retTrue:
    lastChar = currChar;
    return true;

}

Brackets::Brackets(char opening, char closing) : bracketDepthCount(0), lastChar('\0'),
                       inString(false), isDoubleQuoteString(false), closingChar{closing}, openingChar{opening} {}

