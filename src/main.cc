#include <cstdio>
#include <cstdlib>
#include "gl3_prototypes.h"
#include <GL/glew.h>
#include <SDL.h>
#include <glm/glm.hpp>

#include "mesh.h"
#include "shader.h"
#include "camera.h"

SDL_Window* window;
SDL_GLContext context;
SDL_Event e;
bool running = true;

Mesh mesh;
Shader test;
Camera camera;

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("failed to init SDL\n");
        exit(0);
    }

    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
    SDL_GL_SetSwapInterval(1);

    window = SDL_CreateWindow(
        "Title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_OPENGL);

    context = SDL_GL_CreateContext(window);

    glewExperimental = true;
    glewInit();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    //glViewport(0, 0, 1280, 720);
    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
}

void create()
{
    camera.position = glm::vec3(4, 4, 3);
    camera.init(90.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    test.load("../assets/vertex.glsl", "../assets/fragment.glsl");
    test.findUniform("MVP");
    mesh.init();
}

void render()
{
    long now = SDL_GetTicks();
    long then = SDL_GetTicks();
    float delta;

    while (running)
    {
        now = SDL_GetTicks();
        delta = (float)(now - then) / 1000.0f;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
        }

        mesh.update();
        camera.update();

        glm::mat4 mvp = camera.getProjectionMatrix() *
            camera.getViewMatrix() *
            mesh.getModelMatrix();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(test.getProgram());
        glUniformMatrix4fv(
            test.getUniformLocation("MVP"),
            1,
            GL_FALSE,
            &mvp[0][0]);
        mesh.draw();
        glUseProgram(0);

        SDL_GL_SwapWindow(window);

        then = now;
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
