//
// Created by alexey on 03/11/2019.
//

#include "If.h"
#include "../ExpressionParser.h"
#include "../../data/IOR.h"
#include "../../data/datatypes/primitive/PyBoolean.h"
#include "../parsers/GenericParser.h"
#include "../reqeusters/BlockRequester.h"
#include "../reqeusters/CinRequester.h"

If::If() : AbstractKeyword("if") {

}

stringIter_t &If::parse(stringIter_t &ip, stringIter_t &end, IRequester &req) {
    int shouldRun = ExpressionParser::getInstance().parseExpression(ip, end);
    if (shouldRun == -1) return end;
    PyObject* shouldRunO = Memory::getInstance().getData().at(shouldRun);
    if (shouldRunO->getType() != "bool") {
        IOR::getInstance().reportError("Expected bool");
    }
    bool isTrue = ((PyBoolean*)shouldRunO)->value;
    BlockRequester myReq{req};
    GenericParser parser{};

    if (isTrue){
        while (parser.parseLine(myReq));
    } else {
        std::string* line = req.getNext();
        while (line != nullptr && !line->empty() && line->at(0) == '\t'){
            line = req.getNext();
        }
    }
    return end;
}
