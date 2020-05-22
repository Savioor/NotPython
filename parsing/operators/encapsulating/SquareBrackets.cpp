//
// Created by USER on 5/22/2020.
//

#include "SquareBrackets.h"

SquareBrackets::SquareBrackets() : Brackets('[', ']') {

}

PyClass *SquareBrackets::getAsClass() const {
    return nullptr;
}

EncapsulatingOperator *SquareBrackets::supplySelf() {
    return new SquareBrackets();
}
