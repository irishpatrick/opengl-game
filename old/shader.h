#ifndef SHADER_H
#define SHADER_H

#include "gl3_prototypes.h"
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

class Shader
{
public:
    Shader();
    ~Shader();

    void load(const char*, const char*);
    GLuint getProgram();
    GLuint getUniformLocation(const std::string&);

    void findUniform(const std::string&);

private:
    GLuint program;
    std::map<std::string, GLuint> uniforms;
};

#endif /* SHADER_H */
