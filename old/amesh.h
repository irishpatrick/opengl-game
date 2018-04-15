#ifndef AMESH_H
#define AMESH_H

#include "shader.h"

#include <iostream>
#include <string>
#include <vector>
#include <glm/glm.hpp>

using namespace std;

typedef struct {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
} Vertex;

typedef struct {
    unsigned int id;
    string type;
} Texture;

class AMesh {
public:
    AMesh(vector<Vertex>, vector<unsigned int>, vector<Texture>);
    ~AMesh();

    void init();
    void draw(Shader);

    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    unsigned int VAO, VBO, EBO;
};

#endif /* AMESH_H */
