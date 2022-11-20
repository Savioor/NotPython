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

PyClass *PyCodeblock::getElem(PyClass &indexer) const {
    return nullptr;
}

PyClass *PyCodeblock::setElem(PyClass &indexer, PyClass &newElem) {
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
            // TODO this creates issues with reference counting, consider expressions to not count towards references.
            classRecvd->expressionDepth = MemoryManager::getManager().getCurrentDepth();
            MemoryManager::getManager().classesByExpDepth.at(classRecvd->expressionDepth - 1)->push_back(classRecvd);
            return classRecvd;
        }
    }
    return MemoryManager::getManager().getNone();
}

// Just ignores return values.
PyClass *PyCodeblock::runAsClassStructure() {
    std::istringstream ss{code};

    while (ss.rdbuf()->in_avail() > 0) {
        char curr = ss.peek(); // Ignore white space :)
        if (curr == ' ' || curr == '\t' || curr == '\r' || curr == '\n') {
            ss.get();
            continue;
        }
        ExpressionParser::getParser().parseNewExpression(ss);
    }
    return MemoryManager::getManager().getNone();
}

PyCodeblock::PyCodeblock(std::string &&code) : code{code} {
    type = pyCODE_BLOCK;
}
void PyCodeblock::prefixInnit(const std::string& class_name)
{
	this->code.insert(0, class_name + ".__init__(self);");
}

