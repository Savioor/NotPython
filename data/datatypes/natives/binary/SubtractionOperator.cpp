//
// Created by alexey on 08/11/2019.
//

#include "SubtractionOperator.h"
#include "../../primitive/PyPrimitive.h"

SubtractionOperator::SubtractionOperator() : BinaryNativeFunction("-") {

}

objectLoc_t SubtractionOperator::execute(objectLoc_t left, objectLoc_t right) {
    PyObject* leftO = left.first->safelyRetrieve(left.second);
//    PyObject* rightO = right.first->safelyRetrieve(right.second);

    if (leftO->isPrimitive()){
        return ((PyPrimitive *) leftO)->subLeft(right);
    }

    throw "Write this code you dumbfuck";

    return {};
}
