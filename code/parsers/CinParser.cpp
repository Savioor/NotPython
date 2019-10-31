//
// Created by alexey on 30/10/2019.
//

#include <iostream>
#include "CinParser.h"
#include "../../data/IOR.h"

bool CinParser::parseLine(IRequester & req) {
    bool ret = GenericParser::parseLine(req);

    return ret;
}
