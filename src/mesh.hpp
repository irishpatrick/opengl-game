#ifndef MESH_H
#define MESH_H

#include "shader.hpp"

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

class Mesh {
public:
    Mesh(vector<Vertex>, vector<unsigned int>, vector<Texture>);
    ~Mesh();

    void init();
    void draw(Shader);

    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;

    unsigned int VAO, VBO, EBO;
};

#endif /* MESH_H */
