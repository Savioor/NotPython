//
// Created by alexey on 24/10/2019.
//

#include "ExpressionParser.h"
#include "../data/datatypes/primitive/PyString.h"

ExpressionParser::ExpressionParser() {
    specialChars.push_back('"');
    specialChars.push_back('\'');
    specialChars.push_back('+');
    specialChars.push_back('-');
    specialChars.push_back('*');
    specialChars.push_back('/');
    specialChars.push_back(' ');
    specialChars.push_back('&');
    specialChars.push_back('|');
    specialChars.push_back('!');
}

PyObject* ExpressionParser::parseExpression(stringIter_t& startOfExpr, stringIter_t endOfExpr) {

    std::vector<PyObject*> splatData{getSubExpr(startOfExpr, endOfExpr)};

    if (splatData.empty()){
        return nullptr;
    }

    return splatData.at(0); // TODO *EVERYTHING HERE*

}

std::vector<PyObject*> ExpressionParser::getSubExpr(stringIter_t& startOfExpr, stringIter_t endOfExpr) {
    std::vector<PyObject*> ret;
    std::string temp;
    for (auto it = startOfExpr; it != endOfExpr; it++){

        if (*it.base() == ' ') // Ignore all whitespace
            continue;

        switch (*it.base()){
            case '"':
                it++;

                while (*it.base() != '"'){
                    temp.push_back(*it.base());
                    ++it;
                    if (it == endOfExpr){
                        return std::vector<PyObject*>{};
                    }
                }
                ret.push_back(new PyString(std::move(temp)));
                break;
            default:
                // Handle variables\functions here
                break;
        }

        temp = std::string();

    }

    return std::move(ret);
}
