//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_IOR_H
#define BASICPYTHONINTERPRETER_IOR_H

#include <string>
#include <vector>
#include "Memory.h"

typedef std::vector<std::string> strList;


class IOR {

private:
    IOR() = default;

public:
    static IOR& getInstance() {
        static IOR instance;
        return instance;
    };

public:
    void reportError(const std::string&);
    void reportError(const char*);
    void reportError(const std::string&&);

    void reportOut(const std::string&);
    void reportOut(const char*);

    void reportDebug(const std::string&);
    void reportDebug(const std::string&&);
    void reportDebug(const char*);

    void operator=(IOR const&) = delete;
    IOR(IOR const&) = delete;
};


#endif //BASICPYTHONINTERPRETER_IOR_H
