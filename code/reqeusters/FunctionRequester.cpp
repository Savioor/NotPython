//
// Created by alexey on 08/11/2019.
//

#include <cstring>
#include "FunctionRequester.h"

FunctionRequester::FunctionRequester(IRequester &req) : subRequester(req) {
    finishedRequesting = false;
}

std::string *FunctionRequester::getNext(bool affect) {
    if (finishedRequesting){
        return nullptr;
    }
    std::string* ret = subRequester.getNext();
    if (ret == nullptr) return ret;
    if (ret->empty()) return nullptr;
    if (affect) {
        std::string temp{*ret};
        while (temp.at(0) == '\t') {
            temp.erase(0, 1);
        }

        if (strncmp(temp.c_str(), "return ", 7) == 0) {
            finishedRequesting = true;
        }
    }
    return ret;
}
