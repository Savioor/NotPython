//
// Created by alexey on 28/04/2020.
//

#include "Addition.h"

Class *Addition::reduce(Class *left, Class *right) {
    return left->leftAdd(*right);
}

Addition::Addition() : BinaryOperator() {

}
