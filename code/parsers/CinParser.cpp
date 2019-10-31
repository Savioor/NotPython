//
// Created by alexey on 30/10/2019.
//

#include <iostream>
#include "CinParser.h"
#include "../../data/IOR.h"

bool CinParser::parseLine(IRequester & req) {
    bool ret = GenericParser::parseLine(req);

    IOR& ior = IOR::getInstance();

    std::cout << "In[" << ior.getIn().size()-1 << "]: " << ior.getIn().at(ior.getIn().size() - 1) << std::endl;
    std::cout << "Out[" << ior.getOut().size() - 1 << "]: " << ior.getOut().at(ior.getOut().size() - 1)
              << std::endl;
    std::cout << "Err[" << ior.getErr().size() - 1 << "]: " << ior.getErr().at(ior.getErr().size() - 1)
              << std::endl;
    return ret;
}
