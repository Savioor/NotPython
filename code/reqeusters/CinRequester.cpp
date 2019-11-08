//
// Created by alexey on 27/10/2019.
//

#include "CinRequester.h"
#include "../../data/IOR.h"
#include <iostream>

std::string* CinRequester::getNext(bool) {
    auto* str = new std::string;
    std::cout << " >>> ";
    std::getline(std::cin, *str);
    return str;
}
