//
// Created by USER on 5/8/2020.
//

#include "EncapsulatingOperator.h"

EncapsulatingOperator::~EncapsulatingOperator() {
    delete(data);
    data = nullptr;
}

EncapsulatingOperator::EncapsulatingOperator(char oc, char cc, bool an, std::string * data) :
                openingChr{oc}, closingChr{cc}, allowNesting{an}, data{data} {

}
