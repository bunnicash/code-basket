// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>
#include <SDL2/SDL.h>   // windowing framework
#include <glad/glad.h>  // (https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library, https://glad.dav1d.de/)

/* 
g++ sdl-opengl2.cpp glad/src/glad.c -I./glad/include -o test -lSDL2 -ldl

glad should be at ./code-snippets ...

*/
int main (int argc, char* argv[]) {

    // Create window data type
    SDL_Window* window=nullptr;

    // SDL initialization with basic error output 
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Cannot initialize SDL" << SDL_GetError();
        return 1;
    } else {
        std::cout << "Initialized SDL" << std::endl;
    }

    // Define OpenGL version used
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);  // core profile glad, 4.1
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // front buffer and back buffer, refreshing
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    // Create a window
    window = SDL_CreateWindow(
        "Window Title",
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flag (openGL)
    );

    // Check that the window was successfully created
    if (window == nullptr) {
        std::cout << "Could not create window" << SDL_GetError();
        return 1;
    }

    // Setup OpenGL graphics context
    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);
    gladLoadGLLoader(SDL_GL_GetProcAddress);  // for rendering

    // Infinite loop (event loop: https://wiki.libsdl.org/SDL_Event)
    bool gameloop = true;
    while(gameloop) {
        // OpenGL resolution
        glViewport(0,0,640,480);

        // Event loop (input and GL)
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            // Events
            if(event.type == SDL_QUIT) {
                gameloop = false;
            }
            if(event.type == SDL_MOUSEMOTION) {
                std::cout << "Mouse movement.\n";
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);  // array of up to 255 keys with pointer to key state, 0 args
            if (state[SDL_SCANCODE_RETURN]) {
                printf("<RETURN> is pressed.\n");
            }
            if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
                printf("Right and Up Keys Pressed.\n");
            }
        }

        // OpenGL rendering
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // white
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);  // swap between front buffer and back buffer, refreshing
    }

    // Destroy/close window
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}
