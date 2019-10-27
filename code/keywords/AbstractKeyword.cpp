//
// Created by alexey on 25/10/2019.
//

#include "AbstractKeyword.h"

AbstractKeyword::AbstractKeyword(std::string &name) : keyword(name) {
}

AbstractKeyword::AbstractKeyword(std::string &&name) : keyword(name) {

}

AbstractKeyword::AbstractKeyword(char* name) : keyword(name) {

}


const std::string &AbstractKeyword::getKeyword() const {
    return keyword;
}
