// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>
#include <SDL2/SDL.h>   // windowing framework
#include <glad/glad.h>  // (https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library, https://glad.dav1d.de/)

void GLAPIENTRY  // https://www.khronos.org/opengl/wiki/Debug_Output#Examples
MessageCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar* message,
    const void* userParam)
{
    fprintf(
        stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ), 
        type, severity, message );
}

void get_gamepads () {
    int num_gamepads, i;
    num_gamepads = SDL_NumJoysticks();
    std::cout << "Gamepads: " << num_gamepads << std::endl;
    for(i = 0; i < num_gamepads; i++) {
        SDL_Joystick *gamepad = SDL_JoystickOpen(i);
        std::cout << "Name: " << SDL_JoystickName(gamepad) << std::endl;
    }
}

int main (int argc, char* argv[]) {
    // Create window data type
    SDL_Window* window=nullptr;

    // SDL initialization with basic error output 
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0) {
        std::cout << "Cannot initialize SDL" << SDL_GetError();
        return 1;
    }
    get_gamepads();

    // Define OpenGL version used
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);  // core profile glad, 4.1
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // front buffer and back buffer, refreshing
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetSwapInterval(1);  // Vsync to display refresh rate

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

    // Debug output, see GLAPIENTRY
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    // Infinite loop (event loop: https://wiki.libsdl.org/SDL_Event)
    bool gameloop = true;
    while(gameloop) {
        // OpenGL resolution
        glViewport(0,0,640,480);

        // Event loop SDL
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            // Events
            if(event.type == SDL_QUIT) {
                gameloop = false;
            }
            
            const Uint8 *state = SDL_GetKeyboardState(NULL);  // array of up to 255 keys with pointer to key state, 0 args
            if (state[SDL_SCANCODE_ESCAPE]) {
                printf("ESC \n");
                gameloop = false;
            }
            if (state[SDL_SCANCODE_1]) {
                printf("1 \n");
            }
            if (state[SDL_SCANCODE_2]) {
                printf("2 \n");
            }
            if (state[SDL_SCANCODE_3]) {
                printf("3 \n");
            }
            if (state[SDL_SCANCODE_4]) {
                printf("4 \n");
            }
            if (state[SDL_SCANCODE_A]) {
                printf("A \n");
            }
            if (state[SDL_SCANCODE_B]) {
                printf("B \n");
            }
            if (state[SDL_SCANCODE_X]) {
                printf("X \n");
            }
            if (state[SDL_SCANCODE_Y]) {
                printf("Y \n");
            }
        }

        // OpenGL rendering loop
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // white
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);  // swap between front buffer and back buffer, refreshing
    }

    // Destroy/close window
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}