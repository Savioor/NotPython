//
// Created by alexey on 25/05/2020.
//

#include "PyCodeblock.h"
#include "../../parsing/ExpressionParser.h"
#include "primitive/PyInteger.h"
#include "../MemoryManager.h"
#include <sstream>

PyClass *PyCodeblock::leftAdd(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftMult(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftDiv(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftSub(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftModulu(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::leftPower(PyClass const &rightElem) const {
    return nullptr;
}

PyClass *PyCodeblock::negate() const {
    return nullptr;
}

PyBool *PyCodeblock::leftAnd(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftOr(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftEql(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftBigger(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::leftSmaller(PyClass const &rightElem) const {
    return nullptr;
}

PyBool *PyCodeblock::logicalNot() const {
    return nullptr;
}

PyClass *PyCodeblock::call(PyClass &params) {
    return execute();
}

const PyString *PyCodeblock::asString() const {
    return nullptr;
}

PyClass *PyCodeblock::getElem(PyClass const &indexer) const {
    return nullptr;
}

PyClass *PyCodeblock::setElem(PyClass const &indexer, PyClass const &newElem) {
    return nullptr;
}

PyClass *PyCodeblock::execute() {

    std::istringstream ss{code};
    PyClass* classRecvd;

    while (ss.rdbuf()->in_avail() > 0) {
        char curr = ss.peek(); // Ignore white space :)
        if (curr == ' ' || curr == '\t' || curr == '\r' || curr == '\n') {
            ss.get();
            continue;
        }
        classRecvd = ExpressionParser::getParser().parseNewExpression(ss);
        if (classRecvd->isReturnValue) {
            classRecvd->expressionDepth = MemoryManager::getManager().getCurrentDepth(); // TODO test this specific line
            MemoryManager::getManager().classesByExpDepth.at(classRecvd->expressionDepth - 1)->push_back(classRecvd);
            return classRecvd;
        }
    }
    // TODO implement something for the return keyword
    return MemoryManager::getManager().getNone();
}

PyCodeblock::PyCodeblock(std::string &&code) : code{code} {
    type = pyCODE_BLOCK;
}
