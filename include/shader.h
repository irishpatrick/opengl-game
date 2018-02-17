#ifndef SHADER_H
#define SHADER_H

#include "gl3_prototypes.h"
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Shader
{
public:
    Shader();
    ~Shader();

    void load(const char*, const char*);
    GLuint getProgram();

private:
    GLuint program;
};

#endif /* SHADER_H */
