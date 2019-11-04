//
// Created by alexey on 04/11/2019.
//

#include "BlockRequester.h"

std::string *BlockRequester::getNext() {
    std::string* ret = subRequester.getNext();
    if (ret == nullptr) return ret;
    if (ret->empty()) return nullptr;
    if (ret->at(0) != '\t') return nullptr;
    auto* withoutStart = new std::string(*ret);
    withoutStart->erase(0, 1);
    return withoutStart;
}

BlockRequester::BlockRequester(IRequester &req) : subRequester(req) {

}
