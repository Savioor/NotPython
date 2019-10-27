#include <iostream>
#include "code/reqeusters/CinRequester.h"
#include "code/GenericParser.h"

int main() {
    CinRequester req;
    GenericParser parser;

    while (true){
        parser.parseLine(req);
    }

    return 0;
}