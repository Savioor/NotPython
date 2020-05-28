//
// Created by USER on 5/22/2020.
//

#include <sstream>
#include "SquareBrackets.h"
#include "../../../memory/builtins/PyList.h"
#include "../../ExpressionParser.h"

SquareBrackets::SquareBrackets() : Brackets('[', ']', BT_SQUARE) {

}

PyClass *SquareBrackets::getAsClass() const {
    std::istringstream ss{*expr + ";"}; // TODO this is slow and temporary (but it should work)
    return ExpressionParser::getParser().parse(ss);
}

EncapsulatingOperator *SquareBrackets::supplySelf() {
    return new SquareBrackets();
}
