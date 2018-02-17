#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>

class Mesh
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
