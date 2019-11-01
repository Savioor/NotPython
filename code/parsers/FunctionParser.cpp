//
// Created by alexey on 30/10/2019.
//

#include "FunctionParser.h"
#include "../keywords/Return.h"

FunctionParser::FunctionParser() : GenericParser() {
    Return* ret = new Return();
    keywords.push_back(ret);
}
