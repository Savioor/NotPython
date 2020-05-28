//
// Created by USER on 5/22/2020.
//

#include <sstream>
#include "RoundBrackets.h"
#include "../../ExpressionParser.h"

PyClass *RoundBrackets::getAsClass() const {
    std::istringstream ss{*expr + ";"}; // TODO this is slow and temporary (but it should work)
    return ExpressionParser::getParser().parse(ss);
}

RoundBrackets::RoundBrackets() : Brackets('(', ')', BT_ROUND) {

}

EncapsulatingOperator *RoundBrackets::supplySelf() {
    return new RoundBrackets();
}
