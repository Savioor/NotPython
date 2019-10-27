//
// Created by alexey on 24/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_IOR_H
#define BASICPYTHONINTERPRETER_IOR_H

#include <string>
#include <vector>

typedef std::vector<std::string> strList;


class IOR {

private:
    IOR();

    strList in;
    strList out;
    strList err;


public:
    static IOR& getInstance() {
        static IOR instance;
        return instance;
    };

public:
    virtual const strList& getIn() const;
    virtual const strList& getOut() const;
    virtual const strList& getErr() const;

    virtual strList& getIn();
    virtual strList& getOut();
    virtual strList& getErr();
};


#endif //BASICPYTHONINTERPRETER_IOR_H
