#ifndef TEXTURES_H
#define TEXTURES_H

#include <string>
#include <map>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_image.h>

class Textures
{
public:
    static void load(const std::string&, const std::string&);
    static GLuint getId(const std::string&);

private:
    static std::map<std::string, GLuint> tids;
};

#endif /* TEXTURES_H */
