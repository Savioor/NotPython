//
// Created by alexey on 30/10/2019.
//

#include "VectorRequester.h"

std::string *VectorRequester::getNext() {
    if (lastInd == data.size())
        return nullptr;
    return &data.at(lastInd++);
}

VectorRequester::VectorRequester(std::vector<std::string> &v) : data(v) {

}
