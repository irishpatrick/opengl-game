#ifndef OBJLOADER_HPP
#define OBJLOADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "mesh.hpp"

using namespace std;

class ObjLoader {
public:
    static Mesh load(const string&);
};

#endif /* OBJLOADER_HPP */
