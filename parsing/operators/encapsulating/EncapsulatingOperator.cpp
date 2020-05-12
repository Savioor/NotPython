//
// Created by USER on 5/8/2020.
//

#include "EncapsulatingOperator.h"

bool EncapsulatingOperator::isInsideString(bool wasInsideLastChar, bool isDoubleQuote, char lastChar, char thisChar) {
    if (!wasInsideLastChar && (thisChar == '\'' || thisChar == '\"')) {
        return true;
    }
    if (wasInsideLastChar && lastChar != '\\') {
        if (isDoubleQuote) {
            if (thisChar == '"') {
                return false;
            }
        } else {
            if (thisChar == '\''){
                return false;
            }
        }
    }
    return wasInsideLastChar;
}

EncapsulatingOperator::EncapsulatingOperator() : Operator(ENCLOSING) {

}
