#include "objloader.hpp"

Mesh ObjLoader::load(const string& fn) {
    vector<Vertex> v;
    vector<unsigned int> i;

    ifstream in(fn);
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
}
