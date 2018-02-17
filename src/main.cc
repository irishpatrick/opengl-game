#include <cstdio>
#include <cstdlib>
#include "gl3_prototypes.h"
#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>

#include "mesh.h"
#include "shader.h"

SDL_Window* window;
SDL_GLContext context;
SDL_Event e;
bool running = true;

Mesh mesh;
Shader test;

void create()
{
    test.load("../assets/vertex.glsl", "../assets/fragment.glsl");
    mesh.init();
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("failed to init SDL\n");
        exit(0);
    }

    window = SDL_CreateWindow(
        "Title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        768,
        SDL_WINDOW_OPENGL
    );

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);

    context = SDL_GL_CreateContext(window);

    glewExperimental = true;
    glewInit();

    glViewport(0,0,1024,768);
    glClearColor(0.4f,0.4f,0.4f,1.0f);
}

void render()
{
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(test.getProgram());
        mesh.draw();
        glUseProgram(0);


        SDL_GL_SwapWindow(window);
    }
}

void cleanup()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char** argv)
{
    printf("hello world\n");
    init();
    create();
    render();
    cleanup();
}
