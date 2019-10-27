//
// Created by alexey on 25/10/2019.
//

#include <cstring>
#include "GenericParser.h"
#include "keywords/natives/Print.h"
#include "../data/IOR.h"
#include <iostream>

void GenericParser::parseLine(IRequester & requester) {
    std::string& line = *requester.getNext();
    stringIter_t ip = line.begin();
    stringIter_t end = line.end();
    for (auto& key : keywords){
        if (strncmp(key->getKeyword().c_str(), line.c_str(), key->getKeyword().size()) == 0){
            // It's a match!
            ip += key->getKeyword().size();
            ip = key->parse(ip, end);
            break;
        }
    }

    IOR& ior = IOR::getInstance();

    std::cout << "In[" << ior.getIn().size()-1 << "]: " << ior.getIn().at(ior.getIn().size() - 1) << std::endl;
    std::cout << "Out[" << ior.getOut().size()-1 << "]: " << ior.getOut().at(ior.getOut().size() - 1) << std::endl;
    std::cout << "Err[" << ior.getErr().size()-1 << "]: " << ior.getErr().at(ior.getErr().size() - 1) << std::endl;

}

GenericParser::GenericParser() {
    auto* p = new Print();
    keywords.push_back(p);

    IOR::getInstance().getIn().emplace_back("default");
    IOR::getInstance().getErr().emplace_back("default");
    IOR::getInstance().getOut().emplace_back("default");

}
