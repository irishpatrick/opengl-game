#include "textures.h"

std::map<std::string, GLuint> Textures::tids = std::map<std::string, GLuint>();

GLuint Textures::getId(const std::string& name)
{
    if (tids.find(name) != tids.end())
    {
        return tids[name];
    }
    return -1;
}

void Textures::load(const std::string& name, const std::string& fn)
{
    SDL_Surface* surf = IMG_Load(fn.c_str());
    if (surf == NULL)
    {
        printf("couldn't load %s\n", fn.c_str());
        return;
    }

    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    int mode = GL_RGB;
    if (surf->format->BytesPerPixel == 4)
    {
        mode = GL_RGBA;
    }

    glTexImage2D(
        GL_TEXTURE_2D,
        0, mode,
        surf->w, surf->h,
        0, mode,
        GL_UNSIGNED_BYTE,
        surf->pixels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);

    //glBindTexture(GL_TEXTURE_2D, 0);

    tids.insert(std::pair<std::string, GLuint>(name, id));
}
