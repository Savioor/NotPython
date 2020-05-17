//
// Created by alexey on 17/04/2020.
//

#include <iostream>
#include "ExpressionParser.h"
#include "operators/ClassOperator.h"
#include "../memory/builtins/PyInteger.h"
#include "../debug.h"
#include "operators/binary/SimpleBinaryOperator.h"
#include "operators/encapsulating/EncapsulatingOperator.h"
#include "operators/encapsulating/Brackets.h"
#include "operators/encapsulating/StringLiteral.h"
#include "../memory/MemoryManager.h"
#include "../memory/builtins/PyVariable.h"
#include "operators/binary/SetOperator.h"


PyClass *ExpressionParser::parse(std::istream& dataStream) {

    LinkedList<Operator *>* tokenizedExpr = toOperatorList(dataStream);

    while (tokenizedExpr->getStart() != nullptr) {
        Node<Operator*>* toExecute = tokenizedExpr->getStart();
        Node<Operator*>* current = toExecute;

#if EXPR_PARSE_DEBUG
        std::cout << "Parsing with " << tokenizedExpr->size() << " operators left." << std::endl;
#endif

        while (current != nullptr){
            if (current->value->getPrecedence() > toExecute->value->getPrecedence()) {
               toExecute = current;
            }
            current = current->next;
        }
        Operator* currOp = toExecute->value;
        BinaryOperator* asBin;
        PyClass* lClass;
        PyClass* rClass;

        if (tokenizedExpr->getStart() == tokenizedExpr->getEnd()) { // Checking if length == 1
            PyClass* retVal = tokenizedExpr->getStart()->value->getAsClass();
            if (retVal == nullptr) {
                throw std::runtime_error("Reduced expression to single non-class operator");
            }
            return retVal;
        }

        switch (currOp->type) {

            case BINARY:

                if (toExecute->prev == nullptr || toExecute->next == nullptr) {
                    throw std::runtime_error("Binary operator missing left or right operand");
                }
                lClass = toExecute->prev->value->getAsClass();
                rClass = toExecute->next->value->getAsClass();

                // TODO temporary, make better pls
                if (rClass->type == pyVAR){
                    rClass = ((PyVariable*)rClass)->getChild();
                }

                if (lClass == nullptr || rClass == nullptr){
                    throw std::runtime_error("Right or left operand of binary expression are not classes.");
                }
                asBin = (BinaryOperator*) currOp;
                // TODO love mem leaks :)   (it's the ClassOperator obvsly)
                tokenizedExpr->connectAfterV(toExecute, new ClassOperator(asBin->reduce(lClass, rClass)));

                tokenizedExpr->disconnectAndKeepAlive(toExecute->prev);
                tokenizedExpr->disconnectAndKeepAlive(toExecute->next->next);
                tokenizedExpr->disconnectAndKeepAlive(toExecute);

                break;

            case UNARY: // TODO
                break;
            case ENCLOSING: // TODO (might not be needed)
                break;
            case CLASS:
                if (tokenizedExpr->getStart() == tokenizedExpr->getEnd()) { // Easy way to check length == 1
                    return currOp->getAsClass();
                } else {
                    throw std::runtime_error("Can't finish parsing equation");
                }
                break;
        }
    }

    throw std::runtime_error("Can't finish parsing equation");
    return nullptr;
}

ExpressionParser::ExpressionParser() {

    breakerClassMap = std::map<char, int>();

    insertToBreakerMap("+-*/%=!&|<>", MATH_AND_LOGIC); // Mathematical and logical operators
    insertToBreakerMap("()[]\"\'{}", ENCAPSULATING); // Enclosing operator, this breaker class breaks itself
    insertToBreakerMap(" \t\r\n", WHITESPACE); // Whitespace
    insertToBreakerMap(".", DOT_OPERATOR); // Literally just the dot operator

    operators = std::map<std::string, Operator*>();

    operators.insert({"+", new SimpleBinaryOperator(11, PyClass::add)});
    operators.insert({"-", new SimpleBinaryOperator(11, PyClass::sub)});
    operators.insert({"*", new SimpleBinaryOperator(12, PyClass::mult)});
    operators.insert({"/", new SimpleBinaryOperator(12, PyClass::div)});
    operators.insert({"%", new SimpleBinaryOperator(12, PyClass::mod)});
    operators.insert({"**", new SimpleBinaryOperator(15, PyClass::pow)}); // TODO this is subject to changes

    operators.insert({"(", new Brackets()});
    operators.insert({"\"", new StringLiteral(true)});
    operators.insert({"'", new StringLiteral(false)});

    operators.insert({"=", new SetOperator()});


    numbers = std::map<char, char>();
    for (const char* c = "1234567890"; *c != '\0'; c++){
        numbers.insert({*c, *c});
    }

}

void ExpressionParser::insertToBreakerMap(const std::string& chars, int cls) {
    for (int i = 0; i < chars.length(); i++){
        breakerClassMap.insert({chars.at(i), cls});
    }
}

LinkedList<Operator *>* ExpressionParser::toOperatorList(std::istream& dataStream) {

    auto* returnList = new LinkedList<Operator*>();
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

            Operator* op = toOperator(currentOp, context, dataStream);

            if (op != nullptr)
                returnList->addToBackV(op);

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

    Operator* op = toOperator(currentOp, context, dataStream);

    if (op != nullptr)
        returnList->addToBackV(op);

    return returnList;
}

Operator *ExpressionParser::toOperator(const std::string& currentOp, int context, std::istream& stream) {
    if (context == ENCAPSULATING) {

        auto* op = ((EncapsulatingOperator*)operators.at(currentOp))->supplySelf();
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
                // 1. here `new ClassOperator` is never deleted and creates a mem-leak albeit a small one
                // 2. std::atoi is not ideal but it's fine for now. replace later.
                // Integer
                return
                        new ClassOperator(
                                new PyInteger(std::atoi(currentOp.c_str()))
                        );

            } else {

                // Double
                // TODO

            }

        } else {

            // This could be a keyword :/
            // TODO

            // This is a variable
            return
                    new ClassOperator(
                            MemoryManager::getManager().getVariable(currentOp)
                    );

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
