//
// Created by alexey on 25/10/2019.
//

#ifndef BASICPYTHONINTERPRETER_MEMORY_H
#define BASICPYTHONINTERPRETER_MEMORY_H

#include <vector>
#include <map>
#include "datatypes/PyObject.h"

class Memory;

typedef __gnu_cxx::__normal_iterator<char *, std::basic_string<char, std::char_traits<char>, std::allocator<char>>> stringIter_t;

class Memory {
private:
    /**
     * Each pair is an object.
     */
    std::vector<PyObject*> data;
    /**
     * key = a string representing a variable name and an int representing the declaration depth.
     * say the stack trace is 3 functions deep, then the declaration depth is 3. Global variables have declaration depth
     * 0. When we go down a declaration depth, all pointers with that depth die.
     * value = the index of the PyObject in data
     */
    std::map<std::pair<std::string, int>, int> pointerTable;
    /**
     *
     * @return All pointer which match the give name (in any depth)
     */
    std::vector<std::pair<PyObject *, int>> getAllVarMatches(std::string&);

    Memory();

public:

    static Memory& getInstance()
    {
        static Memory instance;
        return instance;
    }

    std::vector<PyObject*>& getData();
    std::map<std::pair<std::string, int>, int> & getPointers();
    /**
     * Remove any elements in data that don't have anything pointing to them.
     * With defragmentation of course.
     */
    void collectGarbage();
    /**
     *
     * @param obj object to add into data
     * @return the pointer to that object
     */
    int alloc(PyObject& obj);
    /**
     *
     * @param obj object to add into data
     * @return the pointer to that object
     */
    inline int alloc(PyObject* obj){
        return alloc(*obj);
    };
    /**
     * Adds a variable pointing to int that matches the current depth
     */
    void allocPointer(std::string&, int);
    /**
     *
     * @return The matching variable of highest depth.
     */
    PyObject* getVariable(std::string&);

    int getPointerByObject(PyObject* inp);

    void reduceDepth(const std::string& varName, int currDepth);

    void killPointer(const std::string& pointerName, int pointerDepth);

    Memory(Memory const&) = delete;
    void operator=(Memory const&) = delete;

    virtual ~Memory();

    int depth;

};


#endif //BASICPYTHONINTERPRETER_MEMORY_H
