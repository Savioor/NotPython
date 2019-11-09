//
// Created by alexey on 25/10/2019.
//

#include <cstring>
#include "GenericParser.h"
#include "../keywords/natives/Print.h"
#include "../../data/IOR.h"
#include "../keywords/Var.h"
#include "../ExpressionParser.h"
#include "../keywords/If.h"

bool GenericParser::parseLine(IRequester & requester) {

    std::string* line = requester.getNext();
    if (line == nullptr){
//        IOR::getInstance().reportError("No input could be found!");
        return false;

    }

    stringIter_t ip = line->begin();
    stringIter_t end = line->end();
    bool found = false;
    for (auto& key : keywords){
        if (strncmp(key->getKeyword().c_str(), line->c_str(), key->getKeyword().size()) == 0){
            if (ip.base()[key->getKeyword().size()] != ' ') continue;

            // It's a match!
#if KEYWORD_DEBUG == true
            IOR::getInstance().reportDebug("Executing keyword " + key->getKeyword());
#endif

            ip += key->getKeyword().size() + 1;
            ip = key->parse(ip, end, requester);
            found = true;
            break;
        }
    }

    if (!found){
        ExpressionParser::getInstance().parseExpression(ip, end);
    }

    return true;

}

GenericParser::GenericParser() {
    auto* p = new Print();
    keywords.push_back(p);
    auto* v = new Var();
    keywords.push_back(v);
    auto* ifKeyword = new If();
    keywords.push_back(ifKeyword);
}

GenericParser::~GenericParser() {
    for (AbstractKeyword*& k : keywords){
        delete(k);
        k = nullptr;
    }
}
