// Copyright (C) 2022 bunnicash "@bunnicash" and licensed under GPL-2.0
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

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

    // Create a window
    window = SDL_CreateWindow(
        "Window Title",
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_SHOWN                   // flag
    );

    // Check that the window was successfully created
    if (window == nullptr) {
        std::cout << "Could not create window" << SDL_GetError();
        return 1;
    }

    // Infinite loop (event loop: https://wiki.libsdl.org/SDL_Event)
    bool gameloop = true;
    while(gameloop) {
        // Event loop
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
    }

    // Destroy/close window
    SDL_DestroyWindow(window);
    SDL_Quit(); 
    return 0;
}
