//
// Created by alexey on 17/04/2020.
//

#include <iostream>
#include <memory>
#include "ExpressionParser.h"
#include "operators/ClassOperator.h"
#include "../memory/builtins/primitive/PyInteger.h"
#include "../debug.h"
#include "operators/binary/SimpleBinaryOperator.h"
#include "operators/encapsulating/EncapsulatingOperator.h"
#include "operators/encapsulating/Brackets.h"
#include "operators/encapsulating/StringLiteral.h"
#include "../memory/MemoryManager.h"
#include "../memory/builtins/PyVariable.h"
#include "operators/binary/SetOperator.h"
#include "operators/encapsulating/RoundBrackets.h"
#include "operators/encapsulating/SquareBrackets.h"
#include "operators/unary/unaryForNext/Print.h"
#include "operators/encapsulating/SquiglyBrackets.h"
#include "operators/binary/nextBinary/If.h"
#include "operators/binary/CommaOperator.h"
#include "operators/special/Def.h"

ExpressionParser ExpressionParser::instance = ExpressionParser();

PyClass *ExpressionParser::parse(std::istream& dataStream) {

    LinkedList<std::shared_ptr<Operator>>* tokenizedExpr = toOperatorList(dataStream);

    MemoryManager::getManager().markAndSweep(); // TODO move this, it's here for testing

    while (tokenizedExpr->getStart() != nullptr) {
        Node<std::shared_ptr<Operator>>* toExecute = tokenizedExpr->getStart();
        Node<std::shared_ptr<Operator>>* current = toExecute;

#if EXPR_PARSE_DEBUG
        std::cout << "Parsing with " << tokenizedExpr->size() << " operators left." << std::endl;
#endif

        while (current != nullptr){
            if (current->value->getPrecedence() > toExecute->value->getPrecedence()) {
               toExecute = current;
            }
            current = current->next;
        }
        std::shared_ptr<Operator> currOp = toExecute->value;
        std::shared_ptr<BinaryOperator> asBin;
        std::shared_ptr<UnaryForNext> asUnar;
        std::shared_ptr<NextBinary> asBinAft;
        std::shared_ptr<TernaryAllAfter> asTer;
        PyClass* lClass;
        PyClass* rClass;
        PyClass* tClass;

        if (tokenizedExpr->getStart() == tokenizedExpr->getEnd()) { // Checking if length == 1
            PyClass* retVal = tokenizedExpr->getStart()->value->getAsClass();
            if (retVal == nullptr) {
                throw std::runtime_error("Reduced expression to single non-class operator");
            }
            delete(tokenizedExpr);
            return retVal;
        }

        switch (currOp->type) {

            case BINARY:

                if (toExecute->prev == nullptr || toExecute->next == nullptr) {
                    throw std::runtime_error("Binary operator missing left or right operand");
                }
                lClass = toExecute->prev->value->getAsClass();
                rClass = toExecute->next->value->getAsClass();

                if (lClass == nullptr || rClass == nullptr){
                    throw std::runtime_error("Right or left operand of binary expression are not classes.");
                }
                asBin = std::dynamic_pointer_cast<BinaryOperator>(currOp);
                tokenizedExpr->connectAfterV(toExecute,
                        std::shared_ptr<Operator>(new ClassOperator(asBin->reduceWithBracketContext(
                                lClass, rClass, toExecute->prev->value->bt, toExecute->next->value->bt
                                ))));

                tokenizedExpr->disconnectAndDeleteValue(toExecute->prev);
                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute);

                break;

            case UNARY:
                if (toExecute->next == nullptr) {
                    throw std::runtime_error("Unary operator missing right operand");
                }
                rClass = toExecute->next->value->getAsClass();

                if (rClass == nullptr){
                    throw std::runtime_error("Right operand of binary expression are not classes.");
                }
                asUnar = std::dynamic_pointer_cast<UnaryForNext>(currOp);
                tokenizedExpr->connectAfterV(toExecute,
                                             std::shared_ptr<Operator>(new ClassOperator(asUnar->expand(rClass))));

                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute);

                break;
            case BINARY_BOTH_AFTER:
                if (toExecute->next == nullptr || toExecute->next->next == nullptr) {
                    throw std::runtime_error("Binary operator missing right or after right operand");
                }
                lClass = toExecute->next->value->getAsClass();
                rClass = toExecute->next->next->value->getAsClass();

                if (lClass == nullptr || rClass == nullptr){
                    throw std::runtime_error("Right or after right operand of binary expression are not classes.");
                }
                asBinAft = std::dynamic_pointer_cast<NextBinary>(currOp);
                tokenizedExpr->connectAfterV(toExecute,
                                             std::shared_ptr<Operator>(new ClassOperator(asBinAft->reduce(lClass, rClass))));

                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute);
                break;
            case TERNARY_ALL_AFTER:
                if (toExecute->next == nullptr || toExecute->next->next == nullptr || toExecute->next->next->next == nullptr) {
                    throw std::runtime_error("Ternary operator operand not found");
                }
                lClass = toExecute->next->value->getAsClass();
                rClass = toExecute->next->next->value->getAsClass();
                tClass = toExecute->next->next->next->value->getAsClass();

                if (lClass == nullptr || rClass == nullptr || tClass == nullptr){
                    throw std::runtime_error("Ternary operator operand is not a class");
                }
                asTer = std::dynamic_pointer_cast<TernaryAllAfter>(currOp);
                tokenizedExpr->connectAfterV(toExecute,
                                             std::shared_ptr<Operator>(new ClassOperator(asTer->reduce(lClass, rClass, tClass))));

                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                tokenizedExpr->disconnectAndDeleteValue(toExecute);
                break;
            case CLASS:
                if (tokenizedExpr->getStart() == tokenizedExpr->getEnd()) { // Easy way to check length == 1
                    delete(tokenizedExpr);
                    return currOp->getAsClass();
                } else {
                    if (toExecute->next != nullptr && toExecute->next->value->bt == BT_ROUND) {
                        rClass = toExecute->next->value->getAsClass();
                        PyClass* funcCall = currOp->getAsClass()->call(*rClass);
                        tokenizedExpr->connectAfterV(toExecute, std::shared_ptr<Operator>(new ClassOperator(funcCall)));
                        tokenizedExpr->disconnectAndDeleteValue(toExecute->next->next);
                        tokenizedExpr->disconnectAndDeleteValue(toExecute);
                    } else {
                        throw std::runtime_error("Reached ClassOperator which is not last in expr");
                    }
                }
                break;
        }
    }

    return MemoryManager::getManager().getNone();
}

ExpressionParser::ExpressionParser() : keywords{}, breakerClassMap{}, operators{}, numbers{} {


    insertToBreakerMap("+-*/%=!&|<>", MATH_AND_LOGIC); // Mathematical and logical operators
    insertToBreakerMap("()[]\"\'{}", ENCAPSULATING); // Enclosing operator, this breaker class breaks itself
    insertToBreakerMap(" \t\r\n", WHITESPACE); // Whitespace
    insertToBreakerMap(".", DOT_OPERATOR); // Literally just the dot operator
    insertToBreakerMap(",", COMMA); // comma

    operators.insert({"+", std::shared_ptr<Operator>(new SimpleBinaryOperator(11, PyClass::add))});
    operators.insert({"-", std::shared_ptr<Operator>(new SimpleBinaryOperator(11, PyClass::sub))});
    operators.insert({"*", std::shared_ptr<Operator>(new SimpleBinaryOperator(12, PyClass::mult))});
    operators.insert({"/", std::shared_ptr<Operator>(new SimpleBinaryOperator(12, PyClass::div))});
    operators.insert({"%", std::shared_ptr<Operator>(new SimpleBinaryOperator(12, PyClass::mod))});
    operators.insert({"**", std::shared_ptr<Operator>(new SimpleBinaryOperator(14, PyClass::pow))});

    operators.insert({"==", std::shared_ptr<Operator>(new SimpleBinaryOperatorBool(8, PyClass::eql))});
    operators.insert({">", std::shared_ptr<Operator>(new SimpleBinaryOperatorBool(9, PyClass::bigger))});
    operators.insert({"<", std::shared_ptr<Operator>(new SimpleBinaryOperatorBool(9, PyClass::smaller))});

    operators.insert({"&&", std::shared_ptr<Operator>(new SimpleBinaryOperatorBool(4, PyClass::pyAnd))});
    operators.insert({"||", std::shared_ptr<Operator>(new SimpleBinaryOperatorBool(3, PyClass::pyOr))});
//    operators.insert({"!", new SimpleBinaryOperatorBool(9, PyClass::smaller)});

    operators.insert({"(", std::shared_ptr<Operator>(new RoundBrackets())});
    operators.insert({"[", std::shared_ptr<Operator>(new SquareBrackets())});
    operators.insert({"\"", std::shared_ptr<Operator>(new StringLiteral(true))});
    operators.insert({"'", std::shared_ptr<Operator>(new StringLiteral(false))});
    operators.insert({",", std::shared_ptr<Operator>(new CommaOperator())});

    operators.insert({"{", std::shared_ptr<Operator>(new SquiglyBrackets())});

    operators.insert({"=", std::shared_ptr<Operator>(new SetOperator())});

    for (const char* c = "1234567890"; *c != '\0'; c++){
        numbers.insert({*c, *c});
    }

    keywords.insert({"print", std::shared_ptr<Operator>(new Print())});
    keywords.insert({"if",std::shared_ptr<Operator>(new If())});
    keywords.insert({"None", std::shared_ptr<Operator>(new ClassOperator(MemoryManager::getManager().getNone()))});
    keywords.insert({"def", std::shared_ptr<Operator>(new Def())});

}

void ExpressionParser::insertToBreakerMap(const std::string& chars, int cls) {
    for (int i = 0; i < chars.length(); i++){
        breakerClassMap.insert({chars.at(i), cls});
    }
}

LinkedList<std::shared_ptr<Operator>>* ExpressionParser::toOperatorList(std::istream& dataStream) {

    auto* returnList = new LinkedList<std::shared_ptr<Operator>>();
    int context = WHITESPACE;
    int currContext;
    std::string currentOp;

    while (true) { // Not sure with while true is the correct thing here.

        currCharRead = dataStream.get();

        if (currCharRead == ';'){ // TODO make this more generic, for now I'll live with this shit
            break;
        }

#if EXPR_PARSE_DEBUG
        std::cout << "Reading '" << currCharRead << "' with current breaker group " << context << std::endl;
#endif
        if (breakerClassMap.count(currCharRead) > 0) {
            currContext = breakerClassMap.at(currCharRead);
        } else {
            currContext = LEGAL_ALPHABETICAL;
        }

        if (context == LEGAL_ALPHABETICAL && currContext == DOT_OPERATOR && numbers.count(currentOp.at(0)) > 0){
            currentOp += currCharRead; // This dot is part of a double representation
        }
        else if (context != currContext || context == ENCAPSULATING) {
            // Context broke let's parse that other piece of shit

#if EXPR_PARSE_DEBUG
            std::cout << "Context switched. Curr op = " << currentOp << std::endl;
#endif

            std::shared_ptr<Operator> op = toOperator(currentOp, context, dataStream);

            if (op)
                returnList->addToBackV(std::shared_ptr<Operator>{op});

            if (context != ENCAPSULATING) {
                currentOp = currCharRead;
            } else {
                currentOp = " ";
                currContext = WHITESPACE;
            }
        } else {
            currentOp += currCharRead; // This char is part of the same "class" so it's part of the same thing
        }

        context = currContext;
    }

    std::shared_ptr<Operator> op = toOperator(currentOp, context, dataStream);

    if (op)
        returnList->addToBackV(std::shared_ptr<Operator>{op});

    return returnList;
}

std::shared_ptr<Operator> ExpressionParser::toOperator(const std::string& currentOp, int context, std::istream& stream) {
    if (context == ENCAPSULATING) {

        std::shared_ptr<EncapsulatingOperator> op{std::dynamic_pointer_cast<EncapsulatingOperator>(operators.at(currentOp))->supplySelf()};
        auto* innards = new std::string(); // TODO do I hear "mem leak"? too bad...!

        if (op->atEncapsulationEnd(currCharRead)) {
            op->supplyInnards(innards);
            return op;
        }
        innards->push_back(currCharRead);
        char curr;

        while(true){
            curr = stream.get();

            if (op->atEncapsulationEnd(curr)) {
                break;
            }

            innards->push_back(curr);
        }

        op->supplyInnards(innards);

        return op;

    } else if (context == LEGAL_ALPHABETICAL) { // This is variables or numbers, handle differently

        if (numbers.count(currentOp.at(0)) > 0) {

            // This must be a number
            if (currentOp.find_first_of('.') == std::string::npos){

                // TODO
                // 1. std::atoi is not ideal but it's fine for now. replace later.
                // Integer
                return
                        std::shared_ptr<Operator>(new ClassOperator(
                                new PyInteger(std::atoi(currentOp.c_str()))
                        ));

            } else {

                // Double
                // TODO

            }

        } else {

            // This could be a keyword
            if (keywords.count(currentOp) > 0) {
                return keywords.at(currentOp);
            }

            // This is a variable
            return
                    std::shared_ptr<Operator>(new ClassOperator(
                            MemoryManager::getManager().getVariable(currentOp)
                    ));

        }

    } else if (context != WHITESPACE) { //Whitespace is literally useless so ignore it

        // This must be an operator
        if (operators.count(currentOp) == 0){
            throw std::runtime_error("Operator not found");
        }
        return operators.at(currentOp);

    }
    return nullptr;
}

ExpressionParser &ExpressionParser::getParser() {
    return instance;
}

PyClass *ExpressionParser::parseNewExpression(std::istream& s) {
    MemoryManager::getManager().increaseExpDepth();
    PyClass* ret = parse(s);
    MemoryManager::getManager().decreaseExpDepth();
    return ret;
}
