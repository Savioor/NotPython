//
// Created by alexey on 28/10/2019.
//

#include "AnonymousObject.h"

#if OBJECT_DEBUG == true
    #include "../IOR.h"
    #include <sstream>
    int AnonymousObject::anonCount = 0;
#endif

AnonymousObject::AnonymousObject() : PyObject("rvalue") {
    #if OBJECT_DEBUG == true
        std::stringstream s;
        s << "Created anon object. Currently " << ++anonCount << " alive.";
        char buffer[50];
        s.getline(buffer, 50);
        IOR::getInstance().reportDebug(buffer);
    #endif
}

PyObject *AnonymousObject::releaseObject() {
    auto* temp = obj;
    obj = nullptr;
    return temp;
}

AnonymousObject::~AnonymousObject() {
    #if OBJECT_DEBUG == true
        std::stringstream s;
        s << "Deleting anon object. Currently " << --anonCount << " alive.";
        if (obj != nullptr){
            s << " Also deleting contained object of type " << obj->getType() << ".";
        }
        char buffer[100];
        s.getline(buffer, 100);
        IOR::getInstance().reportDebug(buffer);
    #endif
    if (obj != nullptr) {
        delete (obj);
        obj = nullptr;
    }
}

std::map<std::string, int> &AnonymousObject::getData() {
    return obj->getData();
}

const std::map<std::string, int> &AnonymousObject::getData() const {
    return obj->getData();
}

AnonymousObject::AnonymousObject(PyObject *o) : PyObject("rvalue"), obj(o) {
    #if OBJECT_DEBUG == true
        std::stringstream s;
        s << "Created anon object. Currently " << ++anonCount << " alive. Object created with object of type " << o->getType() << " inside.";
        char buffer[100];
        s.getline(buffer, 100);
        IOR::getInstance().reportDebug(buffer);
    #endif
}

PyObject *AnonymousObject::getObject() {
    return obj;
}
