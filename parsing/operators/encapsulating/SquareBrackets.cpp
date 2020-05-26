//
// Created by USER on 5/22/2020.
//

#include <sstream>
#include "SquareBrackets.h"
#include "../../../memory/builtins/PyList.h"
#include "../../ExpressionParser.h"

SquareBrackets::SquareBrackets() : Brackets('[', ']') {

}

PyClass *SquareBrackets::getAsClass() const {
    // TODO this whole thing is temp
    int start = 0;
    auto* retList = new PyList();
    ExpressionParser parser{}; // TODO this is slow and temporary
    for (int i = 0; i < expr->size(); i++){
        if (expr->at(i) == ',') {
            std::istringstream ss{expr->substr(start, i - start) + ";"};
            retList->pushBack(parser.parse(ss)); // TODO nullptr time :)
            start = i + 1;
        }
    }

    std::istringstream ss(expr->substr(start, expr->size()) + ";");

    PyClass* lastElem = parser.parse(ss);

    if (lastElem != nullptr) retList->pushBack(lastElem);

    return retList;
}

EncapsulatingOperator *SquareBrackets::supplySelf() {
    return new SquareBrackets();
}
