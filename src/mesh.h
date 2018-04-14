#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "model.h"

class Mesh: public Model
{
public:
    Mesh();
    ~Mesh();

    void init();
    void draw();

private:
    GLuint vao;
    GLuint vbo;
};

#endif /* MESH_H */
